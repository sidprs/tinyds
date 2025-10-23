

class twoDim:
    def __init__(self, grid:list[list[int]], rows:int, cols:int):
        self.grid = [[0 for _ in range(cols)] for _ in range(rows)]
        self.rows = len(grid)
        self.cols = len(grid[0]) if grid else 0
        self.directions = [(1, 0), (0, 1), (-1, 0), (0, -1)]



    def traversal_bfs(self, grid, rows, cols):
        # traverse to the len(rows) - 1, len(cols) - 1 
        visit = set()
        directions = [[1,0],[0,1],[-1,0],[0,-1]]
        q = deque()
        q.append([0,0])

        while q:
            for _ in range(len(q)):
                (r, c) = q.popleft()
                for d_r, d_c in directions:
                    if (r + d_r, c + d_c) not in vist or 
                        r + d_r != 


    def traversal_dfs(self, grid, rows, cols):
        pass


