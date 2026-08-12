class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto it = lower_bound(nums.begin(),nums.end() , target);
        int pos = distance(nums.begin(),it);
        return pos;
    }
};