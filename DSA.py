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
