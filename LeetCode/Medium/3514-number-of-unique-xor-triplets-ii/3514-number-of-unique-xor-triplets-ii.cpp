class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> val;
        int s = nums.size();
        for(int i = 0 ; i < s ; i++){
            for(int j = i ; j < s ; j++){
                val.insert(nums[i]^nums[j]);
            }
        }
        unordered_set<int> result;
        int count = val.size();
        for(int x: val ){
            for(int i = 0 ; i < s ; i++){
                result.insert(x^nums[i]);
            }
        }
        return result.size();
    }
};