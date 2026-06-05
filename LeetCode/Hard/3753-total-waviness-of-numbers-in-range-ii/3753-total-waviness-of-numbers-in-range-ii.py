from functools import cache

class Solution:
    def totalWaviness(self, num1: int, num2: int) -> int:
        def count_waves(limit_val: int) -> int:
            if limit_val < 100:
                return 0
            
            digits = str(limit_val)
            length = len(digits)
            
            @cache
            def search(pos, p2, p1, bound, lead):
                if pos == length:
                    return 0, 1
                
                max_digit = int(digits[pos]) if bound else 9
                total_w, total_c = 0, 0
                
                for digit in range(max_digit + 1):
                    nxt_bound = bound and (digit == max_digit)
                    nxt_lead = lead and (digit == 0)
                    
                    if nxt_lead:
                        nxt_p2, nxt_p1 = -1, -1
                    elif lead:
                        nxt_p2, nxt_p1 = -1, digit
                    else:
                        nxt_p2, nxt_p1 = p1, digit
                    
                    gain = 0
                    if not lead and p2 != -1:
                        if (p1 > p2 and p1 > digit) or (p1 < p2 and p1 < digit):
                            gain = 1
                            
                    sw, sc = search(pos + 1, nxt_p2, nxt_p1, nxt_bound, nxt_lead)
                    total_w += sw + (gain * sc)
                    total_c += sc
                    
                return total_w, total_c
            
            return search(0, -1, -1, True, True)[0]
        
        return count_waves(num2) - count_waves(num1 - 1)