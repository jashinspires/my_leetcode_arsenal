class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> majority_element;
        for(int i = 0 ; i < nums.size() ; i++){
            majority_element[nums[i]]++;
        }
        long long n = nums.size()/2;
        long long val = 0;
        for(auto const& [k,v] : majority_element){
            if(v > n){
               val = k;
            }
        }
        return val;

    }
};