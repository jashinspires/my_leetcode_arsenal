class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> verify = {{nums[0],0}};
        for(int i = 1 ; i < nums.size() ; i++){
            if(verify.find(nums[i]) != verify.end()){
                if(abs(verify[nums[i]] - i) <= k){
                    return true;
                }else if(abs(verify[nums[i]] - i) > k){
                    verify[nums[i]] = i;
                }
            }else {
                verify[nums[i]] = i;
            }
        }
        return false;
    }
};