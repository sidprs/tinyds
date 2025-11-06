class ArrayQuestions:
    def maxFrequency(self, nums: list[int], k:int)-> int:
        cntK = nums.Count(k)
        res = 0

        for i in range(1,51):
            if i == k:
                continue 
            cnt = 0 
            for num in nums:
                if i == nums:
                    cnt +=1
                if i == k:
                    cnt -=1
                cnt = max(0, cnt)
                res = max(res, cnt + cntK)
        return res
    """
    The though process is add 1 to cnt if it can convert nums to i in one operation
    If cnt becomes negative it means that the number is not a good spot in the window
    the max result is the cntK of already existing k numbers + the other cnt of nums that can be
    converted (i) into k
    """


    """
    n jobs given 
    none of the jobs should intersect
    and max profit

    [    ][    ][   ]

    """
    def jobScheduling(self, startTime:list[int], endTime:list[int], profit:list[int])->int:
        jobs = sorted(zip(startTime, endTime, profit))
        print(list(jobs))
        # jobs[i] represents one job 
        
        def dfs(i):
            # do we include this or not 
            pass


    def Triplets(self, x:list[int],y:list[int])-> int:
        minHeap = []
        from collections import defaultdict
        import heapq 
        #heapq.heappush to make it a minheap 
        mp = defaultdict(int)

        for xi, yi in zip(x,y):
            mp = max(mp[xi], yi)
        minHeap = []
        for val in mp.values():
            heapq.heappush(minHeap, val)
            if len(minHeap) > 3: # clever way to pop the largest 3 values 
                heapq.heappop(minHeap)

        return -1 if len(minHeap) < 3 else sum(minHeap)
    

    def MergeInterVals(self, intervals:list[list[int]])->list[list[int]]:
        # lambda sort
        intervals.sort(key=lambda i : i[0])
        output = [intervals[0]]

        #[ 1 , 4] [ 2, 3]
        # if 2 <= 4

        for start, end in intervals:
            lastEnd = output[-1][0]
            if start <= lastEnd:
                output[-1][0] = max(lastEnd, end)
            else:
                output.append([start, end])
        return output
                
    def maxProfit(self, prices:list[int])->int:
        l = 0, maxP = 0
        r = 1, profit = 0
        while r < len(prices):
            if prices[l] < prices[r]:
                profit = r - l
                maxP = max(profit, maxP)
            else:
                l = r
            r+=1
        return maxP

    def bs(self, nums, target):
        l, r = 0, len(nums) - 1

        while(l<= r):
            m = (r + l) // 2
            if nums[m] > target:
                r = m - 1
            elif nums[m] > target:
                l = m + 1
            else:
                return m
    
        return -1
    
    def findMin(self, nums: list[int]) -> int:
        # [1,2,3,4,5]
        # [5,1,2,3,4]
        # if
        """
        if the nums[l] is less than nums[r]
            then its in original sort asc
            res is the first char
        else:
            m is the res min 
            if the left side is sorted search right
            else 
        """ 
        res = nums[0]
        l, r = 0, len(nums) - 1

        while l <= r:
            if nums[l] < nums[r]:
                res = min(res, nums[l])
                return res
            m = (l + r) // 2
            res = min(res, nums[m])
            if nums[l] <= nums[m]:
                r = m -1
            else:
                l = m + 1  
        return res

    def search(self, nums: list[int], target: int) -> int:
        # [1,2,3,4,5]
        # [5,1,2,3,4]
        # [2,3,4,5,1]
        # search for 3 in this 
        """
        case 1: nums[l] < nums[m]
            if the target is in range of l to m
                search l to m
            else:
                search m to r
        case 2: case 1 isnt true
            if target is in range of r to m 
                search m to r 
            else:
                search l to m 
        """
        l, r = 0, len(nums) -  1

        while(l <= r):
            m = (l + r) // 2
            if nums[m] == target:
                return m 
            if nums[l] < nums[m]:
                if target > nums[m] or target < nums[l]:
                    l = m + 1
                else:
                    r = m - 1
            else:
                if target < nums[m] or target > nums[l]:
                    r = m - 1
                else:
                    l = m + 1

        def longestPalindromes(self, input:str)->str:
            
            
            return str
            
                
        
        
        return -1


s = ArrayQuestions()
print(s.jobScheduling([1,2,3],[1,2,3],[1,2,3]))
print(s.jobScheduling([4,2,4,8,2],[5,5,5,10,8],[1,2,8,10,4]))
