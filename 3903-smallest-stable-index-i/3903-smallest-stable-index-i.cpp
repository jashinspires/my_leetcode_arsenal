class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix_max(n);
        vector<long long> suffix_min(n);
        int curr_max = nums[0];
        int curr_min = nums[n-1];
        prefix_max[0] = nums[0];
        suffix_min[n-1] = nums[n-1];
        for(int i = 1 , j = n - 2; (i < n) && (j >= 0) ; i++ , j--){
            prefix_max[i] = max(nums[i],curr_max);
            curr_max = max(nums[i],curr_max);
            suffix_min[j] = min(nums[j],curr_min);
            curr_min = min(nums[j],curr_min);
        }
        for(int i = 0 ; i < n ; i++){
            if(prefix_max[i] - suffix_min[i] <= k){
               return i;
            }
        }
        return -1;
    }
};