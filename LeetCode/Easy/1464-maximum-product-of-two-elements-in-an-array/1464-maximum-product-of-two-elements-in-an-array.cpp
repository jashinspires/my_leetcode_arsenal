class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int s = nums.size();
        int i = s-1 , j = s -2;
        return (nums[i]-1)*(nums[j]-1);
    }
};