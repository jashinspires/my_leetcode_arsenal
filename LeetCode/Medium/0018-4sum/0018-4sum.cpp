class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());
        vector<vector<int>> output;
        int n  = nums.size() ;
        if(n > 3){
        for(int i = 0 ; i < nums.size()-3; i++){
            if( i > 0) if(nums[i] == nums[i-1]) continue;
            for(int j = i + 1 ; j < nums.size() - 2 ; j++){
                if(j > i + 1) if(nums[j] == nums[j - 1]) continue;
                int left = j + 1;
                int right = nums.size() - 1;
                while(left < right){
                    long long val = (long long)nums[left] + nums[right] + nums[j] + nums[i];
                    if(val == target){
                        output.push_back({nums[i],nums[j],nums[left],nums[right]});
                        left++;
                        right--;
                        while(left < right && nums[left] == nums[left - 1]){
                            left++;
                        }
                        while(left < right && nums[right] == nums[right + 1]) right--;
                    }else if(val > target) right--;
                    else if(val < target) left++;
                }
            }
        }
        }else return {};
        return output;
    }
};