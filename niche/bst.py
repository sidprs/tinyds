class TreeNode:
    def __init__(self, val):
        self.right = None
        self.right = None
        self.val = val

    def insert(self, val):
        newnode = TreeNode(val)
        if not self.root:
            return newnode

        if self.root.val > val:
            self.root.right = self.insert(self.root.right, val)
        elif self.root.val < val:
            self.root.left = self.insert(self.root.left, val)



        

