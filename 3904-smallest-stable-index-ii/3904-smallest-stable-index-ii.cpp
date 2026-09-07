class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> suffixmin(n);
        long long min = nums[n-1];
        for(int i = n - 1 ; i >=0 ; i--){
            if( nums[i] <= min ){
                min = nums[i];
                suffixmin[i] = min;
            }else{
                suffixmin[i] = min;
            }
        }
        int index = -1;
        int max = nums[0];
        for(int i = 0 ; i < n ; i++){
            if(nums[i] >= max){
                max = nums[i];
            }
            if(max - suffixmin[i] <= k ){
                index = i ;
                break;
            }
        }
        return index;
    }
};