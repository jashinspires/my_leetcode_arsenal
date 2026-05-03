class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> arr = nums;
        arr.insert(arr.end() , nums.begin() , nums.end()) ;
        return arr;
    }
};