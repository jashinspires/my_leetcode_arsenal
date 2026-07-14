class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> freqMap ;
       for(int num : nums){
        freqMap[num]++;
       }
       vector<vector<int>> buckets(n +1);
       for(auto const&  [num,freq]: freqMap){
        buckets[freq].push_back(num);
       }
        vector<int> output;
       for(int i = n ; i >= 0 ; i--){
            if( !buckets.empty()){
                for(int num: buckets[i]){
                output.push_back(num);
                if(output.size() == k){
                    return output;
                }
                }
            }
       }
       return output;
       
    }
};