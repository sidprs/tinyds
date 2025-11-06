

from collections import defaultdict,Counter
import heapq

class Solution:
    # november 4th 2025
    def findXSum(self, nums: list[int], k: int, x: int) -> list[int]:
        """
        1. count the occurences of all elemen
        2. x most frequent occurences
        3. if two most frequent occurences are tied then keep the largest value i
        4. Sum: frequency * value for each selected element

        x most frequent 

        answer is length = n - k + 1
        answer[i] is the x sum of the subarray nums[i..i + k - 1] 

        """
        n = len(nums)
        answer = [0] 
        heap = []
         
        for i in range(n-k+1):
            sublist = nums[i:i+k]
            freq = Counter(sublist)
            freq_list = [(-count, -num) for num, count in freq.items()]
            heapq.heapify(freq_list)

            x_sum = 0
            pops = min(x, len(freq_list))
            
            for _ in range(pops):
                neg_count, neg_num = heapq.heappop(freq_list)
                count = -neg_count
                num = -neg_num
                x_sum += count * num
            answer.append(x_sum)
            print(answer)



        return answer



    # november 5th 2025
    def findXSum(self, nums: list[int], k: int, x: int) -> list[int]:
        pass

    
