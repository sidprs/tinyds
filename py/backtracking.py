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

when you pop back a stack frame it effects only the index 
the path stays the same since its a object and you are adding a copy 
of the path to the results
--------------------------------------------------
"""



class Solution(object):
    def subsets(self, nums:list[int]):
        results = []

        def backtracking(index,path): 
            if index == len(nums):
                results.append(path[:])
                return 

            path.append(nums[index])
            backtracking(index+1, path)            
            path.pop()

            backtracking(index+1, path)

        backtracking(0 , [])
        return results

    def skipDuplicate(self, nums):
        i = 0
        while(i < len(nums)-1 and nums[i] == nums[i+1]):
            i+=1
    
    def combinations(self, n_range:int, k_size:int, nums:list[int]):
        results = []
        def backtrack(self,n_range, k_size, i , path):
            if len(path) == k_size:
                results.append(path)
                return
            if i > n_range:
                return
            
            for j in range(i, n_range+1):
                path.append(nums[i])
                backtrack(n_range, k_size, j+1, path)
                path.pop()
        backtrack(n_range,k_size,0,[])
        return results
    
    def permutations(self, nums:list[int])-> list[list[int]]:
        results = []

        def backtracking(path):
            if len(nums) == len(path):
                results.append(path[:])
                return
            
            for num in nums:
                if num in path:
                    continue

                path.append(num)
                backtracking(path)
                path.pop()
        backtracking([])
        return results



# trace



"""
b1(0, []) 
    b1(1, [1])
        b1(2, [1,2])
            b1(3, [1,2,3])
                add copy
        b1(2, [1,2,3] -> pop [1,2])
            b2(3, [1,2])
                add copy
    b1(1, [1,2])

     


"""


