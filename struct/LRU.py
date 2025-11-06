

# make a LRU cache from scratch 
# doubly linked list issue



"""
Methods to implement 

Attributes:
    - doubly linked list cache (in array representation)
    - seperate left and right pointers
    - Least Recently Used and Most Recently Used



1. Put (insert into cache of the LRU)
2. Get
3. insert  (insert to the most recently used)
4. remove  (remove the least Recently used)

"""

class Node:
    def __init__(self, key=0:int,  value=0:int):
        self.cache = []
        self.key = key
        self.value = value

class LRU:
    def __init__(self, capacity):
        self.LRU =  Node(-1,-1)  
        self.MRU =  Node(-1,-1)
        self.capacity = capacity
        self.size = 0

    def put(self, key, value):
        pass


    def get(self, key:int) -> int:
        if key in self.cache:
            # update the most recently used 
            # delete the key the reinsert it 

            val = self.cache[key].value
            return val
        else:
            return -1
    
    def put(self, key:int, value)-> None:
        


    def insert(self, key, value):
        

    
    def remove(self, Node):
        # we need to remove the Node

        # A -> B - > C
        # B.prev.next = B.next
        # B.next.prev = B.prev.next
        Node.prev.next = Node.next 
        Node.next.prev = Node.prev
        Node.prev = None
        Node.next = None

        # remove dangling references 

    def insert(self, val):
        # we need to insert it to the MRU 
        rightMostNode = self.right
        newnode = Node(val)
        newnode.next = self.right 
        newnode.next.prev = self.right.prev
        self.right.prev.next = newnode
        self.right.prev = newnode

        #  OLD -> <- R
        #  OLD -> <- NEW -> <- R

        # newnode.next = r
        # newnode.prev = r.prev
        # r.prev.next = newnode
        # r.prev = newnode
         








