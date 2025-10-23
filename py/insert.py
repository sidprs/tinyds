

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
                
