class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int s = nums.size();
        vector<int> arr(s);
        for(int i = 0 ; i < nums.size() ; i++){
            arr[(i+k)%s] = nums[i];
        }
        nums = arr;
    }
};