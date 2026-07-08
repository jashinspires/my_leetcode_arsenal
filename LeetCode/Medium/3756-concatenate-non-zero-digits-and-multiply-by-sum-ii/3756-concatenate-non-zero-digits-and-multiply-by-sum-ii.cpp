class Solution {
public:
    static constexpr int MOD = 1000000007;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<int> id(n, -1);
        vector<int> dig;

        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                id[i] = dig.size();
                dig.push_back(s[i] - '0');
            }
        }

        int m = dig.size();

        vector<long long> pw(m + 1, 1), preNum(m + 1, 0), preSum(m + 1, 0);

        for (int i = 0; i < m; i++) {
            pw[i + 1] = pw[i] * 10 % MOD;
            preNum[i + 1] = (preNum[i] * 10 + dig[i]) % MOD;
            preSum[i + 1] = preSum[i] + dig[i];
        }

        vector<int> nextNZ(n + 1, -1);
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] != '0')
                nextNZ[i] = i;
            else
                nextNZ[i] = nextNZ[i + 1];
        }

        vector<int> prevNZ(n, -1);
        int last = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] != '0') last = i;
            prevNZ[i] = last;
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = nextNZ[q[0]];
            int r = prevNZ[q[1]];

            if (l == -1 || r == -1 || l > q[1] || r < q[0] || l > r) {
                ans.push_back(0);
                continue;
            }

            int L = id[l];
            int R = id[r];

            long long sum = preSum[R + 1] - preSum[L];
            long long x = (preNum[R + 1] - preNum[L] * pw[R - L + 1]) % MOD;
            if (x < 0) x += MOD;

            ans.push_back(x * sum % MOD);
        }

        return ans;
    }
};