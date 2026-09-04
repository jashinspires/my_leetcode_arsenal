class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        set<int> stable_indexes;
        int s = nums.size();
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
                stable_indexes.insert(i);
            }            
        }
        int index = -1;
        if( !stable_indexes.empty()){
            index = *stable_indexes.begin();
        }
        return index;
    }
};