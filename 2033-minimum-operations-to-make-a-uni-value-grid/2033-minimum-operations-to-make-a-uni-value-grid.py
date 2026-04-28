class Solution:
    def minOperations(self, grid: List[List[int]], x: int) -> int:
        nums = []
        remainder = grid[0][0] % x
        for row in grid:
            for val in row:
                if val % x != remainder:
                    return -1
                nums.append(val)
        nums.sort()
        n = len(nums)
        median = nums[n//2]
        min_ops = sum(abs(v - median)//x  for v in nums )
        return min_ops


        