class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<vector<int>> sol; 
        for(int i = 0 ; i < nums.size() ; i++){
            if(i > 0){
                if(nums[i]==nums[i-1]) continue;
            }
            int left = i+1;
            int right = nums.size() - 1;
            while(left < right){
                if(nums[left] + nums[right] == -1*nums[i]){
                    sol.push_back({nums[i],nums[left],nums[right]});
                     left++;
                     right--;
                while( left < right && nums[left] == nums[left-1]){
                    left++;
                }
                while(left < right && nums[right] == nums[right+1]){
                    right--;
                }
                } else if(nums[left] + nums[right] > -1*nums[i]){
                    right--;
                }else if(nums[left] + nums[right] < -1*nums[i]){
                    left++;
                }
               
            }
        }
        return sol;

    }
};