class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        last_lower = {}
        first_upper = {}

        for i, char in enumerate(word):
            if char.islower():
                last_lower[char] = i
            elif char.isupper() and char not in first_upper:
                first_upper[char] = i

        special_count = 0
        for char in last_lower:
            upper_char = char.upper()
            if upper_char in first_upper and last_lower[char] < first_upper[upper_char]:
                special_count += 1

        return special_count
