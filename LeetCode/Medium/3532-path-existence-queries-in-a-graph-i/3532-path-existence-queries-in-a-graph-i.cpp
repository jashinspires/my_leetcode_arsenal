class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> id(n, 0);
        int c = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] - nums[i - 1] > maxDiff) {
                c++;
            }
            id[i] = c;
        }
        
        vector<bool> ans;
        ans.reserve(queries.size());
        for (const auto& q : queries) {
            ans.push_back(id[q[0]] == id[q[1]]);
        }
        return ans;
    }
};