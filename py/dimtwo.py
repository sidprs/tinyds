

class twoDim:
    def __init__(self, grid:list[list[int]], rows:int, cols:int):
        self.grid = [[0 for _ in range(cols)] for _ in range(rows)]
        self.rows = len(grid)
        self.cols = len(grid[0]) if grid else 0
        self.directions = [(1, 0), (0, 1), (-1, 0), (0, -1)]

    def traversal_bfs(self, grid, rows, cols):
        # traverse to the len(rows) - 1, len(cols) - 1 
        
        if not self.grid or self.grid[0][0] == 1:
            return -1
        
        if self.rows == 1 and self.cols == 1:
            return 0

        visit = set()
        directions = [[1,0],[0,1],[-1,0],[0,-1]]
        q = deque()
        q.append([0,0])

        while q:
            for _ in range(len(q)):
                (r, c) = q.popleft()
                for d_r, d_c in directions:
                    new_r, new_c = d_r + r, d_c
                    if (0 <= new_r < self.rows and 0 <= new_c < self.cols and  (new_r, new_c) not in visit and 
                        self.grid[new_r][new_c] == 0):
                    
                        visit.add((new_r, new_c))
                        q.append((new_r, new_c, dist + 1))
        
        return -1  # No path found

    def traversal_dfs(self, grid, rows, cols):
        pass


    
    def isValidSudoku(self, board: list[list[str]]) -> None:
        cols = defaultdict(set)
        rows = defaultdict(set)
        squares = defaultdict(set)

        for i in range(len(boards)):
            for j in range(len(boards[0])):
                if board[i][j] == 1:
                    continue
                if ( board[r][c] in rows[r]
                    or board[r][c] in cols[c]
                    or board[r][c] in squares[(r // 3, c // 3)] ):
                    return False
                cols[c].add(board[r][c])
                rows[r].add(board[r][c])
                squares[(r // 3, c // 3)].add(board[r][c])

        return True



