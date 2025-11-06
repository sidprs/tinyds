



class DP:
    
    def brute(self,r,c,row,col):
        if r == row or c == col:
            return 0
        if r == row-1 or c == col-1:
            return 1
        return self.brute(r+1,c,row,col) + self.brute(r,c+1,row,col)

    def mem(self,r,c,row,col,cache):
        if r == row or c == col:
            return 0
        if r == row-1 or c == col-1:
            return 1    
        if cache[r][c] > 0:
            return cache[r][c]
        
        cache[r][c] = self.mem(r+1,c,row,col,cache) + self.mem(r,c+1,row,col,cache)

        return cache[r][c]

class KnapSackSolution:
    # classic profit, weight, and capacity question  
    def dfs(profit:list[int], weight:list[int], capacity:list[int]):
        return dfsHelper(0, profit, weight, capacity)

    def dfsHelper(i, profit, weight, capacity):
        if i == len(profit):
            return 0 
        
        # skip the current number
        dfsHelper(i+1, profit, weight, capacity)

        #include the current number
        newCapacity = capacity - weight[i]
        if newCapacity >= 0:
            ProfitTemp = profit[i] + dfsHelper(i+1,profit, weight, newCapacity)
            maxProfit = max(maxProfit , ProfitTemp)
        return maxProfit 



    def memo(profit:list[int], weight:list[int], capacity:list[int]):
        return memoization(0, profit, weight,





d = DP()
print(d.brute(0,0,4,4))


d = DP()

print(d.mem(0, 0, 4, 4, [[0] * 4 for i in range(4)]))

