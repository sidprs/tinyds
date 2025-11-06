


class Graph:

    def dfs(grid, r, c, visit):
        ROW, COL = len(grid), len(grid[0])

        if(r == ROW or r == COL or min(r,c) < 0 or grid[r][c] == "1" or (r,c) in visit):
            return 0
        if(r == ROW - 1 or c == COL - 1):
            return 1
        
        visit.add((r,c))
        count = 0
        count += dfs(grid, r+1, c, visit)
        count += dfs(grid, r-1, c, visit)
        count += dfs(grid, r, c+1, visit)
        count += dfs(grid, r, c-1, visit)
        
        visit.remove((r,c))
        return count

    dfs(grid, 0, 0, set()) 


    def bfs(grid, r, c, visit):
        ROW, COL = len(grid), len(grid[0])
        # queue 
        visit = set()
        queue = deque()
        queue.append(grid[0][0])
        visit.add(grid[0][0])

        while queue:
            for _ in range(len(queue)):
                r,c = queue.popleft()
                if r == ROWS - 1 and c == COLS - 1:
                    return distance


                directions = [[0,1],[1,0],[-1,0],[0,-1]]
                for dr, dc in directions:
                    if grid[dr + r][dc + c] == 1 or dr + r == ROWS or dc + c == COLS:
                        continue
                    if grid[dr + r][dc + c] == 0:
                        #queue.append(grid[dr + r][dc + c])
                        #visit.add(grid[dr + r][dc + c])
                        queue.append((nr, nc))
                        visit.add((nr, nc))
        
            distance += 1

        return -1

from collections import deque

def bfs_shortest_path(grid):
    ROWS, COLS = len(grid), len(grid[0])
    
    if grid[0][0] == 1 or grid[ROWS-1][COLS-1] == 1:
        return -1
    
    visit = set()
    queue = deque()
    queue.append((0, 0))
    visit.add((0, 0))
    distance = 0
    
    while queue:
        for _ in range(len(queue)):  # Process entire level
            r, c = queue.popleft()
            
            if r == ROWS - 1 and c == COLS - 1:
                return distance
            
            directions = [[0,1], [1,0], [-1,0], [0,-1]]
            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                
                if (nr < 0 or nr >= ROWS or nc < 0 or nc >= COLS or
                    (nr, nc) in visit or grid[nr][nc] == 1):
                    continue
                
                queue.append((nr, nc))
                visit.add((nr, nc))
        
        distance += 1
    
    return -1




from collections import deque

def bfs_shortest_path(graph, start, end):
    """
    Find shortest path in unweighted graph using adjacency list
    
    Args:
        graph: dict where graph[node] = [list of neighbors]
        start: starting node
        end: target node
    
    Returns:
        shortest distance, or -1 if no path exists
    """
    if start not in graph or end not in graph:
        return -1
    
    visit = set()
    queue = deque()
    queue.append((start, 0))  # (node, distance)
    visit.add(start)
    
    while queue:
        node, dist = queue.popleft()
        
        if node == end:
            return dist
        
        # Explore all neighbors
        for neighbor in graph.get(node, []):
            if neighbor not in visit:
                queue.append((neighbor, dist + 1))
                visit.add(neighbor)
    
    return -1  # No path found


# Example usage:
graph = {
    0: [1, 2],
    1: [0, 3, 4],
    2: [0, 4],
    3: [1, 5],
    4: [1, 2, 5],
    5: [3, 4]
}

print(bfs_shortest_path(graph, 0, 5))  # Output: 3
