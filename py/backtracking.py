"""
BACKTRACKING ALG
--------------------------------------------------

def backtracking(params):
    if base_case_condition:
        results.append(copy_of_solution[:])
        return 
    
    for choice in choices:
        if violates:
            continue

        make_choice
        backtrack(update_param)
        undo_choice 

--------------------------------------------------
"""



class Solution(object):
    def subsets(self, nums:list[int]):
        results = []

        def backtracking(index,path):
            if index == len(nums):
                results.append(path[:])


