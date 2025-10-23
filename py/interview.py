


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





