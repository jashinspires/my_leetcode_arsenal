from collections import Counter

class Solution:
    def smallestPalindrome(self, s: str, k: int) -> str:
        def count_perm(counts, k):
            counts = [c for c in counts if c > 0]
            if not counts:
                return 1
            max_c = max(counts)
            max_idx = counts.index(max_c)
            n = sum(counts)
            y = 1
            for i, c in enumerate(counts):
                if i == max_idx:
                    continue
                for j in range(1, c + 1):
                    y = (y * n) // j
                    n -= 1
                    if y > k:
                        return k + 1
            return y

        freq = Counter(s)
        mid = ""
        half_counts = {}
        for ch in sorted(freq.keys()):
            if freq[ch] % 2 == 1:
                mid = ch
            half_counts[ch] = freq[ch] // 2

        if count_perm(list(half_counts.values()), k) < k:
            return ""

        half_len = len(s) // 2
        res = []
        for _ in range(half_len):
            for ch in sorted(half_counts.keys()):
                if half_counts[ch] > 0:
                    half_counts[ch] -= 1
                    cnt = count_perm(list(half_counts.values()), k)
                    if k <= cnt:
                        res.append(ch)
                        break
                    else:
                        k -= cnt
                        half_counts[ch] += 1

        first_half = "".join(res)
        return first_half + mid + first_half[::-1]