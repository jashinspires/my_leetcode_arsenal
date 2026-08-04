class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int left = 1 ;
        int s = nums.size();
        vector<int> output(s,1);
        for(int i = 0 ; i < s ; ++i){
            output[i] = left;
            left *= nums[i];
        }
        int right = 1;
        for(int i = s - 1 ; i >= 0 ; --i){
            output[i] *= right;
            right *=  nums[i];
        }
        return output;
    }
};