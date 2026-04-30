class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp_prev(n, vector<int>(k + 1, -1));
        dp_prev[0][0] = 0;

        for (int i = 0; i < m; ++i) {
            vector<vector<int>> dp_cur(n, vector<int>(k + 1, -1));
            for (int j = 0; j < n; ++j) {
                int val = grid[i][j];
                int cost = (val == 0) ? 0 : 1;
                int score = val;
                for (int c = cost; c <= k; ++c) {
                    int best = -1;
                    if (i > 0) {
                        int prev = dp_prev[j][c - cost];
                        if (prev != -1)
                            best = max(best, prev + score);
                    }
                    if (j > 0) {
                        int prev = dp_cur[j - 1][c - cost];
                        if (prev != -1)
                            best = max(best, prev + score);
                    }
                    if (i == 0 && j == 0) {
                        if (c == cost && dp_prev[0][0] != -1)
                            best = max(best, dp_prev[0][0] + score);
                    }
                    dp_cur[j][c] = best;
                }
            }
            dp_prev = std::move(dp_cur);
        }
        int ans = -1;
        for (int c = 0; c <= k; ++c) {
            ans = max(ans, dp_prev[n - 1][c]);
        }
        return ans;
    }
};