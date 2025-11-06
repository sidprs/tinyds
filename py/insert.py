

class TreeNode:
    def __init__(self, right=None, left=None, val=0):
        self.right = right
        self.left = left
        self.val = val
        self.res = []

class Graph:
    

    def remove(self, root):
        pass

    def min(self, root):
        pass

    def insert(self, root, value):
        if not root:
            return TreeNode(value)

        if root.val < value: 
            root.right = self.insert(root.right, value)
        elif root.val > value:
            root.left = self.insert(root.left, value)
        
        return root

    def inorder(self, root):
        
        res = []
        if not root:
            return 
        
        self.inorder(root.left)
        res.append(root.val)
        self.inorder(root.right)
        return res 
        

    def inorderDFS(self, root):
        stack = []
        res = []
        curr = root
        while stack or res:
            while curr:
                
