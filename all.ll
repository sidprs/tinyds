class ListNode:
    def __init__(self, val=0, next=None, prev=None):
        self.val = val, self.next = next, self.prev = prev


class LinkedList:
    def __init__(self, capacity):
        self.capacity = capacity
        self.tail = ListNode()
        self.head = ListNode()

    
    def pushAtIndex(self, i) -> int:
        pass 
class Solution:
    def hasPathSum(self, root, targetSum: int) -> bool:
        def dfs(node, current_sum):
            if not node:
                return False
            
            # Add current node's value to sum
            current_sum += node.val
            
            # Check if it's a leaf node and sum matches target
            if not node.left and not node.right:
                return current_sum == targetSum
            
            # Recursively check left and right subtrees
            return dfs(node.left, current_sum) or dfs(node.right, current_sum)
        
        return dfs(root, 0)


# Alternative solution if you want to collect all paths
class SolutionWithPaths:
    def findPathsWithSum(self, root, targetSum: int):
        """Returns all root-to-leaf paths that sum to targetSum"""
        result = []
        
        def dfs(node, path, current_sum):
            if not node:
                return
            
            # Add current node to path and sum
            path.append(node.val)
            current_sum += node.val
            
            # If leaf node and sum matches, save the path
            if not node.left and not node.right:
                if current_sum == targetSum:
                    result.append(path[:])
            else:
                # Continue exploring
                dfs(node.left, path, current_sum)
                dfs(node.right, path, current_sum)
            
            # Backtrack
            path.pop()
        
        dfs(root, [], 0)
        return result



class Node:
    def __init__(self, key, val):
        self.key, self.val = key, val
        self.prev = self.next = None

class LRUCache:
    def __init__(self, capacity: int):
        self.cap = capacity
        self.cache = {}  # map key to node

        self.left, self.right = Node(0, 0), Node(0, 0)
        self.left.next, self.right.prev = self.right, self.left

    def remove(self, node):
        prev, nxt = node.prev, node.next
        prev.next, nxt.prev = nxt, prev

    def insert(self, node):
        prev, nxt = self.right.prev, self.right
        prev.next = nxt.prev = node
        node.next, node.prev = nxt, prev

    def get(self, key: int) -> int:
        if key in self.cache:
            self.remove(self.cache[key])
            self.insert(self.cache[key])
            return self.cache[key].val
        return -1

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self.remove(self.cache[key])
        self.cache[key] = Node(key, value)
        self.insert(self.cache[key])

        if len(self.cache) > self.cap:
            lru = self.left.next
            self.remove(lru)
            del self.cache[lru.key]

import heapq
from collections import defaultdict


class stringRelplacement:
    def solution(self, s:str ) -> str:
        res = ""
        counter = defaultdict(int)
        for c in s:
            counter[ord(c)-ord('a')] += 1

        arr_c = [[-cnt, char] for cnt, char in counter.items()]

        heapq.heapify(arr_c)



        return res


"""
You are given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

You can return any possible rearrangement of s or return "" if not posssible.

Example 1:

Input: s = "axyy"

freq y -2
     x -1
     a -1

use most frequent word
then cannot use the word we just previously used
then pick the second frequent word 
repeat until the heapq is empty 

Output: "xyay"
"""
from collections import Counter
class Solution:
    def reorganizeString(self, s: str) -> str:
        count = Counter(s)
        maxHeap = [[-cnt, char] for char, cnt in count.items()]
        heapq.heapify(maxHeap)

        prev = None
        res = ""
        while maxHeap or prev:
            if prev and not maxHeap:
                return ""

            cnt, char = heapq.heappop(maxHeap)
            res += char
            cnt += 1

            if prev:
                heapq.heappush(maxHeap, prev)
                prev = None

            if cnt != 0:
                prev = [cnt, char]

        return res





class TrieNode:
    def __init__(self):
        self.children = {}
        self.word = False
    
class Trie:
    def __init__(self):
        self.root = TrieNode()


    def insert(self, word:str):
        
        curr = self.root
        for c in word:
            if c not in curr.children:
                curr.children = TrieNode()
            curr = curr.children[c]
        curr.word = True


    def search(self, word:str)->bool:
        curr = self.root

        for c in word:
            if c not in curr.children:
                return False
            curr = curr.children[c]
        return curr.word



class Node:
    def __init__(self, val):
        self.val = val
        self.right = None
        self.left = None


    def dfs_inorder_iter(self, root):
        # L N R 
        curr = root
        stack = []
        
        while curr or stack:
            while curr:
                stack.append(curr)
                curr = curr.left
            curr = stack.pop()
            print(curr.val)
            stack.append(curr)
            curr = curr.right
        
    def dfs_inorder_rec(self,root):

        if not root:
            return 

        inorder_iter(root.left)
        print(root.val)
        inorder_iter(root.right)


"""
BACKTRACKING ALG
--------------------------------------------------

def backtracking(params):
    if base_case_condition:
        results.append(copy_of_solution[:])
        return 
    
    for choice in choices:
        if violates:
            continue

        make_choice
        backtrack(update_param)
        undo_choice 

when you pop back a stack frame it effects only the index 
the path stays the same since its a object and you are adding a copy 
of the path to the results
--------------------------------------------------
"""



class Solution(object):
    def subsets(self, nums:list[int]):
        results = []

        def backtracking(index,path): 
            if index == len(nums):
                results.append(path[:])
                return 

            path.append(nums[index])
            backtracking(index+1, path)            
            path.pop()

            backtracking(index+1, path)

        backtracking(0 , [])
        return results

    def skipDuplicate(self, nums):
        i = 0
        while(i < len(nums)-1 and nums[i] == nums[i+1]):
            i+=1
    
    def combinations(self, n_range:int, k_size:int, nums:list[int]):
        results = []
        def backtrack(self,n_range, k_size, i , path):
            if len(path) == k_size:
                results.append(path)
                return
            if i > n_range:
                return
            
            for j in range(i, n_range+1):
                path.append(nums[i])
                backtrack(n_range, k_size, j+1, path)
                path.pop()
        backtrack(n_range,k_size,0,[])
        return results
    
    def permutations(self, nums:list[int])-> list[list[int]]:
        results = []

        def backtracking(path):
            if len(nums) == len(path):
                results.append(path[:])
                return
            
            for num in nums:
                if num in path:
                    continue

                path.append(num)
                backtracking(path)
                path.pop()
        backtracking([])
        return results



# trace



"""
b1(0, []) 
    b1(1, [1])
        b1(2, [1,2])
            b1(3, [1,2,3])
                add copy
        b1(2, [1,2,3] -> pop [1,2])
            b2(3, [1,2])
                add copy
    b1(1, [1,2])

     


"""




class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.right = right
        self.left = left


class BST:
    def __init__(self, root):
        root = TreeNode(0)

    def insertBST(self, root, val):
        if not root:
            return TreeNode(val)

        if root.val < val:
            root.right = self.insertBST(root.right, val)
        elif root.val > val:
            root.left = self.insertBST(root.left, val)
        
        return root

    def removeBST(self, root, val):
        if not root:
            return None

        if root.val < val:
            root.right = self.removeBST(root.right, val)
        elif root.val > val:
            root.left = self.removeBST(root.left, val)
        else:
            if not root.left:
                return root.right
            elif not root.right:
                return root.left
            
            else:
                minNode = self.returnMin(root.right)
                root.val = minNode.val
                root.right = self.removeBST(root.right, minNode.val)
        return root

    def returnMin(self, root):
        curr = root
        while(curr and curr.left):
            curr = curr.left
        return curr



class Solution:
    def inorderTraversal(self, root: [TreeNode]) -> [int]:
        res = []
        def inorder(root):
            if not root:
                return 
            inorder(root.left)
            # once it hits null pops one from that 
            res.append(root.val)
            inorder(root.right)
        inorder(root)
        return res


    def inorderIteratively(self, root):
        stack = []
        res = []
        curr = root

        # while the node is valid
        # go down to the left most node
        # if that node is not valid, pop the parent and go right
        # if the right side is not valid then pop the stack

        while curr or stack:
            while curr:
                stack.append(curr.val)
                curr = curr.left
            
            node = stack.pop()
            res.append(node.val)
            curr = curr.right
            # the loop repeats


        # we are at a null point 
        


class DisjointSet:
    def __init__(self, n):
        self.paren = {}
        self.height = {}
            
        # Disjoint(3)
        # creates 3 nodes with each parent pointing at
        for i in range(1, n+1):
            self.paren[i] = i
            self.height[i] = 0


    def find(self, n):
        p = self.paren[n]

        while p != self.paren[p]:

            # path compression
            self.paren[p] = self.paren[self.paren[p]]
            p = self.paren[p]
        return p 


    def union(self, n1, n2):
        p1, p2 = self.find(n1), self.find(n2)

        if p1 == p2:
            return False
        
        if self.rank[p1] > self.rank[p2]:
            self.par[p2] = p1
        elif self.rank[p1] < self.rank[p2]:
            self.par[p1] = p2
        else:
            self.par[p1] = p2
            self.rank[p2] += 1
        return True


    def redudunantCycles(self):
        pass
    def connectedComponents(self):
        pass


class TreeNode:
    def __init__(self, right=None, left=None, val=0):
        self.right = right
        self.left = left
        self.val = val
        self.res = []

class Graph:
    

    def remove(self, root):
        

    def min(self, root):


    def insert(self, root, value):
        if not root:
            return TreeNode(val)

        if root.val < value: 
            root.right = self.insert(root.right, value)
        elif root.val > value:
            root.left = self.insert(root.left, value)
        
        return root

    def inorderT(self, root):
       res = [] 
        def inorder(root):
            if not root:
                return 
            
            self.inorder(root.left)
            res.append(root.val)
            self.inorder(root.left)
        self.inorder(root)
        return res

    def inorderDFS(self, root):
        stack = []
        res = []
        curr = root
        while stack or res:
            while curr:
                



# q1 : max sum 
# q2 : min sum of paths
# q3 : distance between two nodes
# q4 : biggest value in the tree
# q5 : smallest value in the tree
# q6 : largest diameter of the tree (longest left length + longest right length)

class Node:
    def __init__(self, parent,val=0,right=None, left=None):
        self.parent = parent
        self.val = val
        self.right = right 
        self.left = left

class Solution:
     def q1(self, root):
         # we need to find the max sum of paths in a tree given the root node:
         # logic : we need to go dfs down every path and then calculate each sum and then find the max 


# 
"""
    a
   b c
 d e  g
"""

        final_sum = 0

        res = []
        def dfs(root, path, sumv):
            nonlocal final_sum
            

            if not root:
                return 
           
            sumv += root.val
            path.append(root.val)

            if not root.right and not root.left:
                res.append(path[:])
                final_sum = max(final_sum, sumv)
            else:
                dfs(root.left, path, sumv)
                dfs(root.right, path, sumv)

            path.pop()
        dfs(root,[], 0)
        return final_sum 


    def maxPathSumBFS(root):
        if not root:
            return 0
        
        # Store (node, sum_so_far) as tuples
        q = deque([(root, root.val)])
        max_sum = float('-inf')
        
        while q:
            node, current_sum = q.popleft()  # Get node AND its path sum
            
            # If leaf, check if max
            if not node.left and not node.right:
                max_sum = max(max_sum, current_sum)
            
            # Add children with UPDATED sums
            if node.left:
                q.append((node.left, current_sum + node.left.val))
            if node.right:
                q.append((node.right, current_sum + node.right.val))
        
        return max_sum
            

    def q1a(self, root):
        # BFS for levels 
        q = deque()

        if root:
            q.append(root)

        while q: 
            level_sum = 0
            for _ in range(len(q)):
                node = q.popleft()
                level_sum += node.val
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            res = max(res, level_sum)
        return res





     def q2(self, root):
         



     
     def q3(self, root):
         pass
     
     def q4(self, root):
         pass
     
     def q5(self, root):
         pass



class Node(self, val):
    self.val = val


class LinkedList:
    """
    h n1 n2 n3  t 
     => => => =>
     <= <= <= <= 
    """
    def __init__(self, val):
        self.val = val
        self.next = Node(-1) 
        self.prev = Node(-1)
        self.index = index

    def insertFront(self, val):


        # h-> newNode -> 

        newNode = ListNode(val)
        newNode.next = self.head.next
        newNode.prev = self.head

        self.head.next.prev = newNode
        self.head.next = newNode



    def insertTail(self, val):

        # n <- tail
       newNode = ListNode(val)
       newNode.next = self.tail
       newNode.prev = self.tail.prev

       self.tail.next.prev = newNode
       self.tail.prev = newNode

    def insert(self, node, val):
        curr = self.head
        while curr.val != i and curr != self.tail:
            curr = curr.next

        if curr == self.tail:
            print(f"Value {target_val} not found!")
        return
        
        newNode = ListNode(val)
        newNode.prev = curr.prev
        newNode.next = curr
        curr.prev.next = newNode
        curr.prev = newNode







hello my name is siya dubey
hello my 

from collections import defaultdict
class UnitConverter:
    def __init__(self, mp : list[tuple[str, int]]):
        """
        create adjacenceny List 
        """
        self.adjlist = defaultdict(list)
        for src, dst in mp:
            if src not in self.adjlist:
                self.adjlist[src] = []
            if dst not in self.adjlist:
                self.adjlist[dst] = []
            self.adjlist[src].append(dst)






class loops(object):
    def enum(self, nums:list[int]):
        for i, v in enumerate(nums):
            print(str(i) + " " + str(v))

    def zip_arr(self, nums1:list[int], num2:list[int]):
        for xi.yi in zip(num1, nums2):
            print(str(xi) + " " + str(yi))
        


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
    
    def minNode(self, root):
        curr = root
        while curr and curr.left:
            curr = curr.left
        return curr

    def remove(self, root, val):
        if not root:
            return 
        if val > root.val:
            root.right = self.root(root.right, val)
        elif val < root.val:
            root.left = self.root(root.left ,val)
        else: 
            minNodeInTree = self.minNode(root.right)
            root.val = minNodeInTree.val
            root.right = self.remove(root.right, minNodeInTree.val)
        return root
    
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
                r,c = popleft()
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


class matmul:
    def __init__(self, kernel, input):
        self.kernel = kernel
        self.inputImage = input
    
    def imageMap(self, kernel, image):
        pass


arr = [1,2,3]
hi = [3,4,5]
n = zip(arr,hi)
print(list((i,j) for i,j in n))


class Node:
    def __init__(self, val, right=0, left=0):
        self.val = val
        self.right = right
        self.left = left



class BinarySearchTree:
    def insert(self, val: int) -> Node:
        if not root:
            return Node(val)

        if root.val < val:
            root.right = self.insertBST(root.right, val)
        elif root.val > val:
            root.left = self.insertBST(root.left, val)
        
        return root
 

 class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        stack = []
        curr = root
        
        while stack or curr:
            while curr:
                stack.append(curr)
                curr = curr.left
            curr = stack.pop() # visiting the node 
            k -= 1
            if k == 0:
                return curr.val

            # Move to right subtree
            curr = curr.right 

        return -1   


    def remove(self, key: int) -> Node:
        if not root:
            return
        if root.val < key:
            remove(root.right, key)
        elif root.val > key:
            remove(root.left , key)
        else:
            # we are at the node we need to delete
            # 


    def bfs(self, root):
        pass


    def dfs_rec(self, root):
        pass



    def dfs_iter(self, root):
        pass


    def bfs_rec(self,root):
        pass
class ArrayQuestions:
    def maxFrequency(self, nums: list[int], k:int)-> int:
        cntK = nums.Count(k)
        res = 0

        for i in range(1,51):
            if i == k:
                continue 
            cnt = 0 
            for num in nums:
                if i == nums:
                    cnt +=1
                if i == k:
                    cnt -=1
                cnt = max(0, cnt)
                res = max(res, cnt + cntK)
        return res
    """
    The though process is add 1 to cnt if it can convert nums to i in one operation
    If cnt becomes negative it means that the number is not a good spot in the window
    the max result is the cntK of already existing k numbers + the other cnt of nums that can be
    converted (i) into k
    """


    """
    n jobs given 
    none of the jobs should intersect
    and max profit

    [    ][    ][   ]

    """
    def jobScheduling(self, startTime:list[int], endTime:list[int], profit:list[int])->int:
        jobs = sorted(zip(startTime, endTime, profit))
        print(list(jobs))
        # jobs[i] represents one job 
        
        def dfs(i):
            # do we include this or not 
            pass



    def Triplets(self, x:list[int],y:list[int])-> int:
        minHeap = []
        from collections import defaultdict
        import heapq 
        #heapq.heappush to make it a minheap 
        mp = defaultdict(int)

        for xi, yi in zip(x,y):
            mp = max(mp[xi], yi)
        minHeap = []
        for val in mp.values():
            heapq.heappush(minHeap, val)
            if len(minHeap) > 3: # clever way to pop the largest 3 values 
                heapq.heappop(minHeap)

        return -1 if len(minHeap) < 3 else sum(minHeap)

s = ArrayQuestions()
print(s.jobScheduling([1,2,3],[1,2,3],[1,2,3]))
print(s.jobScheduling([4,2,4,8,2],[5,5,5,10,8],[1,2,8,10,4]))
