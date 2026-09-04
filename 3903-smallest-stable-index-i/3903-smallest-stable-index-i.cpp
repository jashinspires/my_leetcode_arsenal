class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int s = nums.size();
        int index = -1;
        for(int i = 0 ; i < s ; i++){
            int max = INT_MIN;
            int min = INT_MAX;
            if( i == 0 ){
                max = nums[i];
            }
            else {
                for(int j = 0 ; j <= i ; j++){
                    if(nums[j] > max) max = nums[j];
                }
            }
            if(i == s - 1){
                min = nums[i];
            }else {
                for(int k = i ; k < s ; k++){
                    if(nums[k] < min) min = nums[k];
                }
            }
            if(abs(max-min) <= k){
                index = i;
                break;
            }            
        }
        
        return index;
    }
};