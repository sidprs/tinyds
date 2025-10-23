

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
