
from collections import defaultdict, deque
"""
This contains the major data structures in python
Dynamic Array (Resizable Array)   	
Singly Linked List   	
 Double-ended Queue       	
 Binary Search Tree       	
 Hash Table       	
 Heap       	
 Graph
    - Topological Sort
    - Dijkstra 
    - Prims
    - BFS (Matrix)
    - DFS (Matrix)
 Disjoint Set (Union-Find)       	
 Segment Tree       
 """


# Disjoint Union Set
class DSU:
    def __init__(self, n:int):
        self.par = {}
        self.rank = {}
        for i in range(n+1):
            self.par[i] = i
            self.rank[i] = 0

    
    def Union_Find(self, n):
        p = self.par[n]
        while p != self.par[n]:
            self.par[n] = self.par[self.par[n]]
            p = self.par[n]
        return p 

    def Union(self, n1, n2):
        p1, p2 = self.Union_Find(n1), self.Union_Find(n2)

        if p1 == p2:
            return False
        
        if self.rank[p1] < self.rank[p2]:
            self.par[p1] = p2
        elif self.rank[p2] < self.rank[p1]:
            self.par[p2] = p1
        else:
            self.par[p1]  = p2
            self.rank[p2] += 1


class TreeNode:
    def __init__(self, val=0, right=None, left=None):
        self.val = val
        self.right = right
        self.left = left

class BST:
    """
    ---------------------------------------------------
    1. Insert
    2. Remove
    3. BST / DFS / BFS
    4. Iterative DFS
    ---------------------------------------------------
    """
    def __init__(self):
        self.root = None
    

    def insert(self, root, val):
        curr = root
        if curr is None:
            return TreeNode(0)
        if curr > val:
            return self.insert(root.right, val)
        elif curr < val:
            return self.insert(root.left, val)
        return root
    
    def remove(self, root, val):
        # case if there is 
    
    def inorder_rec_dfs(self, root):
        res = []
        if not root:
            return 
        self.inorder_rec_dfs(root.left)
        res.append(root.val)
        self.inorder_rec_dfs(root.right)
        return res

    def inorder_rec_dfs(self, root):
        stack = []
        curr = root
        res = []
        while stack or curr:
            if curr:
                res.append(curr)
                stack.append(curr)
                curr = curr.left
            else:
                curr = stack.pop()
                print(curr.val)
                curr = curr.right



    def inorder_bfs(self, root):
        q = deque()
        if not root:
            q.append([root])

        res = []
        while q:
            for _ in range(len(q)):
                curr = q.popleft()
                res.append(curr.val)
                if curr.left:
                    q.append(curr.left)
                if curr.right:
                    q.append(curr.right)
                
                curr_level+=1
        return res


class TopologicalSort:
    def __init__(self, val:int):
        self.adjList = defaultdict(list)
        self.visited = set()
        self.visiting = set()
    """
    ---------------------------------------------------
    1. Create adjList, populate it 
    2. DFS + Cycle Detection
    2a. visited : already completed notes 
        visiting: nodes that are in the current path 
    ---------------------------------------------------
    """
    def topo(self, n:int, edges:list[tuple[int]])-> list[int]:
        topsort = []
        for src, dst in edges:
            self.adjList[src].append(dst)

        def dfs(src):
            if src in self.visiting:
                return False # a cycle is detected
            if src in self.visited:
                return True

            for neighbor in self.adjList[src]:
                if not dfs(neighbor):
                    return False # a cycle has been detected

            self.visiting.add(src)
            self.visited.add(src)
            topsort.append(src)
            return True

        for i in range(n):
            if not dfs(i):
                return []

        topsort.reverse()
        return topsort
            







        








