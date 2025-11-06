
from collections import deque
class Node:
    def __init__(self, val):
        self.val = val
        self.right = None
        self.left = None
    

class BST_problems:
    def __init__(self, root):
        self.root = root

    def dfs_invert_tree(self,root):
        # go down the tree 
        # once hit none, pop back
        # go right, once hit none
        # pop back

        if not root:
            return
        root.left, root.right =root.right, root.left
        self.dfs_invert_tree(root.left)
        self.dfs_invert_tree(root.right)

        return root

    def bfs_invert_tree(self, root):
        if not root:
            return 
        q = deque.append([root])      

        while q:
            for _ in range(len(q)): # not needed
                curr = q.popleft()
                curr.left, curr.right = curr.right, curr.left
                if curr.left:
                    q.append(curr.left)
                if curr.right:
                    q.append(curr.right)
        return root
    
    def max_depth_dfs_iter(self, root):
        stack = [[root, 1]]

        while stack:
            curr,depth = stack.pop()
            if curr:
                maxd = max(maxd, depth)
                stack.append(curr.left, depth+1)
                stack.append(curr.right, depth+1)
        return maxd  

    def maxDepth_bfs(self, root) -> int:
        depth = 0
        res = 0
        if not root:
            return res

        if root:
            q = deque([root])
        while q:
            for i in range(len(q)):
                node = q.popleft()
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            depth+=1 
        return depth

    def lowestCommonAncestor(self, root, p, q ):
        """
        The lowest common ancestor between two nodes p and q is the lowest 
        node in a tree T such that both p and q as descendants. 
        The ancestor is allowed to be a descendant of itself
        """
        # if p.val > root.val and q.val > root.val go to the right
        # if the

        curr = root

        while curr:
            if curr.val > p.val and curr > q.val:
                curr = curr.right
            elif curr.val< p.val and curr < q.val:
                curr = curr.left

            else:
                return curr
        return -1 
  
    def subtree(self, t, s):
        if not t:
            return False
        if not s:
            return True

        if self.isSame(t,s):
            return True
        return (self.subtree(t, s.left) or 
                self.subtree(t, s.right)) 


    def isSame(self, s, t):
        if not s and not t:
            return True

        if s and t and s.val == t.val:
            return (self.isSame(s.left,t.left) and
                    self.isSame(s.right,t.right))
        return False




        

        
    
