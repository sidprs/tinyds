
from collections import defaultdict


class Solution:
    def __init__(self, para1):
        pass

    def longestPalindrome(self, s:str)->str:
        # find the longest palindrome in a string
        for i in range(len(s)):
            l, r = i,i 
            while(l >= 0 and r < len(s) and s[l] == s[r]):
                if (r - l + 1 > resLen):
                    resLen = r- l + 1
                    resIdx = l
                r+=1
                l-=1 
            l, r = i, i + 1 
            while(l >= 0 and r < len(s) and s[l] == s[r]):
                if (r - l + 1 > resLen):
                    resLen = r- l + 1
                    resIdx = l
                r+=1
                l-=1 

        return s[resIdx : resIdx + resLen] 

    



    def checkInclusion(self, s1:str, s2:str) -> bool:

        '''
        Return True if s2 contains permutation of s1
        
        Steps
        1. go through the  s2  and if it contains char from s1_set then continue 
        2. if it contains all of s2 characters continously then return True
        3. return False after the loop ends

        '''

        l = 0
        from collections import defaultdict
        
        frequency_s1 = defaultdict(int)
        for c in s1:
            frequency_s1[c] += 1
        # now it creates a hash of character -> count
        
        frequency_s2 = defaultdict(int)
        
        need = len(s1)
        for i in range(len(s2)):
            counts2, count = defaultdict(int), 0
            for j in range(i,len(s2)):
                counts2[s[j]] += 1
                if counts2[s2[j]] < frequency_s1[s2[j]]:
                    break
                if counts2[s2[j]] == frequency_s1[s2[j]]:
                    count +=1

                if count == need:
                    return True

        return False


    def groupAnagrams(self, inputs:list[str]) -> list[list[str]]:
        
        pass

    def longestSubarray(nums):
        length = 0
        l = 0
        
        for r in range(len(nums)):
            if nums[l] != nums[r]:
                l = r 
            length = max(length, r - l + 1)
        return length

# find length of the minimum size subarray where the sum is 
# greater than or equal to the target.
# assume all values in the input are positive.
# o(n)
    def shortestsubarray(nums, target):
        l, total = 0, 0
        length = float("inf")
        
        for r in range(len(nums)):
            total += nums[r]
            while total >= target:
                length = min(r - l + 1, length)
                total -= nums[l]
                l += 1
        return 0 if length == float("inf") else length


    def subarraySum(self, nums: list[int], k:int)-> int:
        result = 0
        prevMap = defaultdict(int)
        prevMap[0] = 1
        total = 0
        for n in nums:
            total += n

            if total - k in prevMap:
                result += prevMap[total-k]

            prevMap[total-k]+=1

        return result
