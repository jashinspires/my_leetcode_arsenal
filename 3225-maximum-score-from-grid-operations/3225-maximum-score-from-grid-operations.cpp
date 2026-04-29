class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 1)
            return 0;

        vector<vector<long long>> pref(n + 1, vector<long long>(n, 0));
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < n; ++i) {
                pref[i + 1][j] = pref[i][j] + grid[i][j];
            }
        }

        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));

        for (int curr = 0; curr <= n; ++curr) {
            for (int prev = 0; prev <= n; ++prev) {
                dp[curr][prev] = max(0LL, pref[curr][0] - pref[prev][0]);
            }
        }

        for (int j = 1; j < n - 1; ++j) {
            vector<vector<long long>> new_dp(n + 1,
                                             vector<long long>(n + 1, 0));
            for (int curr = 0; curr <= n; ++curr) {
                vector<long long> pref_max(n + 1, 0);
                vector<long long> suff_max(n + 1, 0);

                pref_max[0] = dp[curr][0];
                for (int p = 1; p <= n; ++p) {
                    pref_max[p] = max(pref_max[p - 1], dp[curr][p]);
                }

                suff_max[n] =
                    dp[curr][n] + max(0LL, pref[n][j] - pref[curr][j]);
                for (int p = n - 1; p >= 0; --p) {
                    long long val =
                        dp[curr][p] + max(0LL, pref[p][j] - pref[curr][j]);
                    suff_max[p] = max(suff_max[p + 1], val);
                }

                for (int nxt = 0; nxt <= n; ++nxt) {
                    long long ans1 =
                        pref_max[nxt] + max(0LL, pref[nxt][j] - pref[curr][j]);
                    long long ans2 = (nxt + 1 <= n) ? suff_max[nxt + 1] : -1LL;
                    new_dp[nxt][curr] = max(ans1, ans2);
                }
            }
            dp = new_dp;
        }

        long long max_score = 0;
        for (int curr = 0; curr <= n; ++curr) {
            for (int prev = 0; prev <= n; ++prev) {
                long long final_score =
                    dp[curr][prev] +
                    max(0LL, pref[prev][n - 1] - pref[curr][n - 1]);
                max_score = max(max_score, final_score);
            }
        }

        return max_score;
    }
};