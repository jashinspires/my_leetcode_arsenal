class Solution:
    def minimumPushes(self, word: str) -> int:
        n = len(word)
        ans = 0
        pushed = 1
        
        while n > 0:
            count = min(n, 8)
            ans += count * pushed
            n -= count
            pushed += 1
            
        return ans