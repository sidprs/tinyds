"""
---------------------------------------------------------------------
topo sort has two variations that i will implement 
one of the implementation is DFS and other is Kahn (BFS - Queue)
i will demonstrate understanding by completing Course Scheduler - I, II 
---------------------------------------------------------------------
"""



class TopoLogical:
    def Top_dfs(self, edges : list[tuple[int]]):
        adjlist = defaultdict(list)
        for (u, v) in edges:
            if u not in adjlist:
                adjlist[u] = {}
            if v not in adjlist:
                adjlist[v] = {}
            adjlist[u].append(v)
        
        #created adjlist 
    
        
    # visit means we visited the node we viisted all the neighbors
    # we added the post order n, l , r
    def dfs(visited, 

            







from collections import defaultdict, deque
"""
---------------------------------------------------------------------
Topological sort when the edges could be a acyclic or cycles 
Must be cycle detection and return [] if there is not solution
returns a path using DFS 
---------------------------------------------------------------------

"""
def toposort(self, edges:list[list[int]])->list[int]:
    """
    visit    : the nodes visted
    visiting : nodes being visited in the current dfs call  
    """ 
    topSort, visited, visiting = [], set(), set()
    # first do dfs in post order then reverse 
    adjList = defaultdict(list)
    for src, dst in edges:
        adjList[src].append(dst)

    


    def dfs(src:int):
        if src in visited:    # has been reached before
            return True 
        if src in visiting: # along the current path 
            return False
        
        # we visit a node 
        visiting.add(src)

        for neighbor in adjList[src]:
            if not dfs(neighbor):
                return False # cycle

        visiting.remove(src)
        visited.add(src)
        topSort.append(src)

        return True

    for i in range(n):
        if not dfs(i):
            return [] #detected a cycle 

    return topSort.reverse()
         
class CSI:
    def canFinish_dfs(self, edges:list[list[int]]) -> bool:
        #prevMap = { i: [] for i in range(numCourses)}
        adjList = defaultdict(list)
        for src, dst in edges:
            if src not in adjList:
                adjList[src] = []
            if dst not in adjList:
                adjList[dst] = []
            adjList[src].append(dst)
        visit = set()
        def dfs(crs):
            if crs in visit: 
                return False
            if adjList[crs] == []: 
                return True
            visit.add(crs)
            for pre in adjList[crs]:
                if not dfs(pre): 
                    return False
            visit.remove(crs)
            adjList[crs] = [] # no adj list for the current
            return True

    def canFinish_bfs(self, numCourses:int, edges:list[list[int]]) -> bool:
    
        """
        will create a indegree , adjlist <= defaultdict
        use the dst with the indegree of 0 and then do BFS traversal 
        """ 
        
        indegree = [0] * numCourses 
        adjList = defaultdict(list)
        for src, dst in edges:
            if src not in adjList: adjList[src] = []
            if dst not in adjList: adjList[dst] = []
            adjList[src].append(dst)
            indegree[dst] += 1

        # TODO I dont understand how to do canFinish_bfs because Kahn is fucking hard 
        q = deque()
        

class CSII:
    """
    ---------------------------------------------------------------------
    same thing as before just printing the order
    and also detecting cycles (like the last one too CSI)
    ---------------------------------------------------------------------
    """
    def canFinish_dfs(self, edges:list[list[int]], numCourses:int)->list:

        pass
