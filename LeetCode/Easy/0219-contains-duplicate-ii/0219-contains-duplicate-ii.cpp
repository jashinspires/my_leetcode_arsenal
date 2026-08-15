class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> verify;
        
        for (int i = 0; i < nums.size(); i++) {
            if (verify.find(nums[i]) != verify.end() && i - verify[nums[i]] <= k) {
                return true;
            }
            verify[nums[i]] = i;
        }
        
        return false;
    }
};