class Solution {
private:
    int dfs(int i, const vector<int>& arr, int d, vector<int>& dp) {
        if (dp[i] != -1) return dp[i];
        
        int res = 1;
        int n = arr.size();
        
        for (int j = i + 1; j <= min(n - 1, i + d); ++j) {
            if (arr[i] <= arr[j]) break;
            res = max(res, 1 + dfs(j, arr, d, dp));
        }
        
        for (int j = i - 1; j >= max(0, i - d); --j) {
            if (arr[i] <= arr[j]) break;
            res = max(res, 1 + dfs(j, arr, d, dp));
        }
        
        return dp[i] = res;
    }

public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, -1);
        int max_visited = 0;
        
        for (int i = 0; i < n; ++i) {
            max_visited = max(max_visited, dfs(i, arr, d, dp));
        }
        
        return max_visited;
    }
};