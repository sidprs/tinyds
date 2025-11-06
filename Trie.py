

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


