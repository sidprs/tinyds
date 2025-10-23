

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
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
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
        
