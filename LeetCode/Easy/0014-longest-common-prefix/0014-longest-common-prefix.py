class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        firstWord = strs[0]
        for i in range(len(firstWord)):
            char = firstWord[i]
            for word in strs[1:]:
                if i >= len(word) or word[i] != char:
                    return firstWord[:i]
        return firstWord