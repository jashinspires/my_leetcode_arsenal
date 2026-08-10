class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> majority;
        for(int i : nums){
            majority[i]++;        }
    int n = nums.size()/3;
    vector<int> output;
        for(const auto& [key , value]:majority) {
            if(value > n){
                output.push_back(key);
            }
        }
        return output;
    }
};