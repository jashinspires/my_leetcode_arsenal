class Solution:
    def earliestFinishTime(self, landStartTime: List[int], landDuration: List[int], waterStartTime: List[int], waterDuration: List[int]) -> int:
        ans = float('inf')
        
        for i in range(len(landStartTime)):
            for j in range(len(waterStartTime)):
                finish_land_first = max(landStartTime[i] + landDuration[i], waterStartTime[j]) + waterDuration[j]
                finish_water_first = max(waterStartTime[j] + waterDuration[j], landStartTime[i]) + landDuration[i]
                ans = min(ans, finish_land_first, finish_water_first)
                
        return ans