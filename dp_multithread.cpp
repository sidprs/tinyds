// dp_multithread.cpp
using namespace std;

using ll = long long;

// ---------- 1) Brute-force recursive ----------
ll brute(int r, int c, int row, int col) {
    if (r == row || c == col) return 0;
    if (r == row - 1 || c == col - 1) return 1;
    return brute(r + 1, c, row, col) + brute(r, c + 1, row, col);
}

// ---------- 2) Top-down memoization (single-threaded) ----------
ll memo_rec(int r, int c, int row, int col, vector<vector<ll>>& cache) {
    if (r == row || c == col) return 0;
    if (r == row - 1 || c == col - 1) return 1;
    if (cache[r][c] != -1) return cache[r][c];
    cache[r][c] = memo_rec(r + 1, c, row, col, cache) + memo_rec(r, c + 1, row, col, cache);
    return cache[r][c];
}

// ---------- 3) Concurrent top-down memoization ----------
// We'll use per-cell:
//   - cache: stores computed value (when ready)
//   - state: 0=not started, 1=computing, 2=done
//   - mtx and cv to allow waiting if some other thread is computing the same cell.
//
// This implementation starts two async tasks (down and right) with std::async(launch::async)
// when computing subproblems so work can run in parallel.

ll memo_rec_concurrent(int r, int c, int row, int col,
                       vector<vector<ll>>& cache,
                       vector<vector<int>>& state,
                       vector<vector<mutex>>& mtx,
                       vector<vector<condition_variable>>& cvs) {
    if (r == row || c == col) return 0;
    if (r == row - 1 || c == col - 1) return 1;

    // Acquire lock for this cell
    {
        unique_lock<mutex> lk(mtx[r][c]);
        if (state[r][c] == 2) {
            // already computed
            return cache[r][c];
        }
        if (state[r][c] == 1) {
            // someone else is computing -> wait until done
            cvs[r][c].wait(lk, [&]{ return state[r][c] == 2; });
            return cache[r][c];
        }
        // state == 0 -> mark as computing and release lock to do work
        state[r][c] = 1;
    }

    // Compute children concurrently
    auto fut_down = std::async(std::launch::async,
        [&](int rr, int cc){ return memo_rec_concurrent(rr, cc, row, col, cache, state, mtx, cvs); },
        r + 1, c);

    auto fut_right = std::async(std::launch::async,
        [&](int rr, int cc){ return memo_rec_concurrent(rr, cc, row, col, cache, state, mtx, cvs); },
        r, c + 1);

    ll down = fut_down.get();
    ll right = fut_right.get();
    ll result = down + right;

    // store result and notify waiters
    {
        unique_lock<mutex> lk(mtx[r][c]);
        cache[r][c] = result;
        state[r][c] = 2;
    }
    cvs[r][c].notify_all();
    return result;
}

// ---------- Helper: iterative DP (bottom-up) - for reference ----------
ll iterative_dp(int row, int col) {
    // number of rows = row, cols = col (matching the python usage where cache is row x col)
    vector<vector<ll>> dp(row + 1, vector<ll>(col + 1, 0));
    // We treat dp[r][c] as number of paths from (r,c) to the "edge" using same base rules.
    // Actually with given base case: if r==row or c==col => 0. If r==row-1 or c==col-1 => 1
    for (int r = row - 1; r >= 0; --r) {
        for (int c = col - 1; c >= 0; --c) {
            if (r == row - 1 || c == col - 1) dp[r][c] = 1;
            else dp[r][c] = dp[r + 1][c] + dp[r][c + 1];
        }
    }
    return dp[0][0];
}

int main() {
    int row = 4, col = 4;

    // 1) brute
    cout << "brute(0,0,4,4) = " << brute(0, 0, row, col) << "\n";

    // 2) memoized single-threaded
    vector<vector<ll>> cache(row, vector<ll>(col, -1));
    cout << "memo_rec(0,0,4,4) = " << memo_rec(0, 0, row, col, cache) << "\n";

    // 3) iterative bottom-up
    cout << "iterative_dp(4,4) = " << iterative_dp(row, col) << "\n";

    // 4) concurrent memoized
    vector<vector<ll>> cache_c(row, vector<ll>(col, -1));
    vector<vector<int>> state(row, vector<int>(col, 0));
    vector<vector<mutex>> mtx(row, vector<mutex>(col));
    vector<vector<condition_variable>> cvs(row, vector<condition_variable>(col));

    cout << "memo_rec_concurrent(0,0,4,4) = "
         << memo_rec_concurrent(0, 0, row, col, cache_c, state, mtx, cvs) << "\n";

    return 0;
}

