class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0 ;
        int r = 1 ;
        int sum = nums[0];
        int minwin = INT_MAX;
        if(sum >= target) return 1;
        while(r < nums.size()){
            sum += nums[r];
            while(sum >= target){
                minwin = min(minwin,r - l + 1);
                sum -= nums[l];
                l++;
            }
            r++;
        }
        return minwin == INT_MAX?0:minwin;
    }
};