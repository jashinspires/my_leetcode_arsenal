from typing import List


class Solution:
    def getResults(self, queries: List[List[int]]) -> List[bool]:
        M = max(q[1] for q in queries) + 5
        bit = [0] * (M + 1)
        tree = [0] * (2 * M)

        def update_bit(idx, val):
            while idx <= M:
                bit[idx] += val
                idx += idx & (-idx)

        def query_bit(idx):
            s = 0
            while idx > 0:
                s += bit[idx]
                idx -= idx & (-idx)
            return s

        def find_kth(k):
            idx = 0
            shift = 1 << 16
            while shift > 0:
                if idx + shift <= M and bit[idx + shift] < k:
                    idx += shift
                    k -= bit[idx]
                shift >>= 1
            return idx + 1

        def update_seg(pos, value):
            pos += M
            tree[pos] = value
            pos >>= 1
            while pos > 0:
                tree[pos] = max(tree[2 * pos], tree[2 * pos + 1])
                pos >>= 1

        def query_seg(left, right):
            res = 0
            left += M
            right += M
            while left < right:
                if left & 1:
                    res = max(res, tree[left])
                    left += 1
                if right & 1:
                    right -= 1
                    res = max(res, tree[right])
                left >>= 1
                right >>= 1
            return res

        results = []
        for q in queries:
            if q[0] == 1:
                x = q[1]
                cnt_L = query_bit(x - 1)
                L = find_kth(cnt_L) if cnt_L > 0 else 0

                cnt_R = query_bit(x)
                total = query_bit(M)
                R = find_kth(cnt_R + 1) if cnt_R < total else None

                update_bit(x, 1)
                update_seg(x, x - L)
                if R is not None:
                    update_seg(R, R - x)
            else:
                x, sz = q[1], q[2]
                cnt_L = query_bit(x)
                L = find_kth(cnt_L) if cnt_L > 0 else 0

                max_gap = max(query_seg(0, L + 1), x - L)
                results.append(max_gap >= sz)

        return results
