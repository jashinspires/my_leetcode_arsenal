class Solution {
public:
    int maxProduct(int n) {
        string nums = to_string(n);
        vector<int> vals;
        for( auto ch: nums){
            vals.push_back(ch -'0');
        }
        sort(vals.begin(),vals.end());
        int s = vals.size();
        return vals[s-1]*vals[s-2];
    }
};