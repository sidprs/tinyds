
class DSU:
    def __init__(self, n):
        self.par = {}
        self.height = {} 
        self.components = n
        for i in range(n+1):
            self.par[i] = i
            self.height = 0

    def find(self, n):
        p = self.par[n]
        while p != self.par[n]:
            # path compression
            self.par[n] = self.par[self.par[n]]
            p = self.par[n]
        return p 
    
    def union(self, n1,n2):
        p1, p2 = self.find(n1), self.find(n2)
        
        if p1 == p2:
            return False
        if p1.rank < p2.rank:
            self.par[p2] = p1
        elif p1.rank > p2.rank:
            self.par[p1] = p2
        else:
            self.par[p1] = p2
            self.height[p2]+=1
            self.components += 1
        return True
    
class Solution:
    def connectedComponents(self, n:int, edges : list[tuple[int]]):
        '''
        This solutions uses DSU as the way to calcuate it 
        The union shows True if they are not already connected and will decrement the total nodes by 1 since it was unioned into another 
        The union shows False if they are not unioned and they are already connected ( Cycle Detection )
        '''

        dsu = DSU(n)
        res = n 

        for (u, v) in edges:
            if dsu.union(u,v):
                res -=1
        return res

    def initialize(list_edges : list[tuple[int]]):
        # return a new visit and adjList 
        from collections import defaultdict
        adjList = defaultdict(list)
        visit = set()
        for (u,v) in list_edges:
            adjList[u].append(v)
            adjList[v].append(u)
        return adjList, visit

    def DepthForSearchSolution(self, n:int, edges: list[tuple[int]]):
        """
        This solution will be similar but using the recursive DFS
        """   
        adjList, visit = self.create_AdjList(edges)

        def dfs(node):
            for neighbor_node in adjList[node]:
                if neighbor_node not in visit:
                    visit.add(neighbor_node )
                    dfs(neighbor_node)
        result = 0 
        for node in range(n):
            if node not in visit:
                visit.add(node)
                dfs(node)
                result += 1
        return result

    def C_BreadForSearch(self, n:int, edges: list[tuple[int]]):
        """
        same thing but iterative bfs
        """
        adjList , visit = self.initialize(edges)
        from collections import deque

        def bfs(self, node):
            q = deque
            q.append[node]

            while q:
                #for _ in range(len(q)):
                curr = q.popleft()
                for neighbor_node in adjList[curr]:
                    if neighbor_node not in visit:
                        visit.add(neighbor_node)
                        q.append(neighbor_node)
        result = 0 
        for node in range(n):
            if node not in visit:
                visit.add(node)
                # bfs adds the visited nodes 
                bfs(node)
                result +=1 
        return result

class Search2D:
    def __init__(self):
        pass