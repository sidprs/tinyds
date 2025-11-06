"""
------------------------------------------------------------|
includes all sorting
includes segment tree structure - (query, update)

------------------------------------------------------------|

"""
class SegmentTree:
    def __init__(self, total, LIdx, RIdx):
        self.left_child = None
        self.right_child = None
        self.total = total
        self.L = LIdx
        self.R = RIdx
    
    def build(nums , L, R):
        if L == R:
            return SegmentTree(nums[L] ,L , R)
        
   
        
        