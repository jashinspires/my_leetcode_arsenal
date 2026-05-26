class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        ls = set()
        us = set()
        for char in word:
            if char.islower():
                ls.add(char)
            elif char.isupper():
                us.add(char)
        special_count = 0 
        for char in ls:
            if char.upper() in us:
                special_count += 1
        return special_count
    