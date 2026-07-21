class Solution:
    def findMissingAndRepeatedValues(self, grid: List[List[int]]) -> List[int]:
        n = len(grid)
        N = n*n
        expected_sum = N*(N+1)/2
        actual_sum = 0
        squaredSumExp = N*(N+1)*(2*N + 1)/6
        squaredSumAct = 0
        for i in range(n):
            for j in range(n):
                actual_sum += grid[i][j]
                squaredSumAct += grid[i][j]*grid[i][j]
        diff = actual_sum - expected_sum
        Squared_diff = squaredSumAct - squaredSumExp
        sumXY = Squared_diff/diff
        missing = int((sumXY - diff)/2)
        repeated = int((sumXY + diff)/2)
        return [repeated,missing]
        
        
        
        
        