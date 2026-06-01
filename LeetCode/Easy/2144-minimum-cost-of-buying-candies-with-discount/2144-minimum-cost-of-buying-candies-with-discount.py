from typing import List
class Solution:
    def minimumCost(self, cost: List[int]) -> int:
        cost.sort(reverse=True)
        total = 0
        for i, value in enumerate(cost):
            if i % 3 != 2:
                total += value

        return total
