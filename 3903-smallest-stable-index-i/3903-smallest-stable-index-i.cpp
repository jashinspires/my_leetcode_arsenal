class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> suffix_min(n);
        suffix_min[n-1] = nums[n-1];
        for(int j = n - 2; j >=0 ; j--){
            suffix_min[j] = min(nums[j],suffix_min[j+1]);
        }
        int curr_max = nums[0];
        for(int i = 0 ; i < n ; i++){
            curr_max = max(nums[i],curr_max);
            if((curr_max - suffix_min[i]) <= k){
                return i;
            }
        }
        return -1;
    }
};