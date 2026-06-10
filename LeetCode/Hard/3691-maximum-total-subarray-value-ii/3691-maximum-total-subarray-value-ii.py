import heapq

class Solution:
    def maxTotalValue(self, nums: list[int], k: int) -> int:
        n = len(nums) 
        log_table = [0] * (n + 1)
        for i in range(2, n + 1):
            log_table[i] = log_table[i >> 1] + 1
                        
        levels = log_table[n] + 1
        
        st_max = [None] * levels
        st_min = [None] * levels
        st_max[0] = nums
        st_min[0] = nums
        
        for j in range(1, levels):
            shift = 1 << (j - 1)
            row_len = n - (1 << j) + 1
            st_max[j] = [0] * row_len
            st_min[j] = [0] * row_len
            
            prev_max = st_max[j - 1]
            prev_min = st_min[j - 1]
            
            for i in range(row_len):
                st_max[j][i] = max(prev_max[i], prev_max[i + shift])
                st_min[j][i] = min(prev_min[i], prev_min[i + shift])
                
        def get_value(L: int, R: int) -> int:
            if L == R:
                return 0
            j = log_table[R - L + 1]
            rem = R - (1 << j) + 1
            mx = max(st_max[j][L], st_max[j][rem])
            mn = min(st_min[j][L], st_min[j][rem])
            return mx - mn

        heap = []
        for l in range(n):
            val = get_value(l, n - 1)
            heap.append((-val, l, n - 1))
            
        heapq.heapify(heap)
        
        total_max_value = 0
        for _ in range(k):
            neg_val, l, r = heapq.heappop(heap)
            total_max_value -= neg_val
            
            if r > l:
                next_r = r - 1
                next_val = get_value(l, next_r)
                heapq.heappush(heap, (-next_val, l, next_r))
                
        return total_max_value