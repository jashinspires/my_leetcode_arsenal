class Solution:
    def smallestPalindrome(self, s: str) -> str:
        half_size = len(s)//2
        half_string = s[0:half_size]
        half_string = "".join(sorted(s[:half_size]))
        rev_half_string = half_string[::-1]
        if len(s)%2 == 1:
            return half_string + s[half_size] + rev_half_string
        else:
            return half_string + rev_half_string      