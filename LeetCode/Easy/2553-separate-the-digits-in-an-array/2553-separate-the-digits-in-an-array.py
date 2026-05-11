class Solution:
    def separateDigits(self, nums: List[int]) -> List[int]:
        answer = [int(d) for n in nums for d in str(n)]
        return answer