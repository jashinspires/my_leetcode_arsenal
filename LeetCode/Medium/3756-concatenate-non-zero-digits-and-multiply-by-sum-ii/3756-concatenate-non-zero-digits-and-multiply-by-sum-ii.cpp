class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int M = s.length();
        long long MOD = 1e9 + 7;

        vector<long long> pow10(M + 1, 1);
        for (int i = 1; i <= M; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }
        
        vector<int> digit_sum_prefix(M + 1, 0);
        vector<int> count_prefix(M + 1, 0);
        vector<long long> concat_prefix(M + 1, 0);
        
        for (int i = 1; i <= M; i++) {
            int digit = s[i - 1] - '0';
            digit_sum_prefix[i] = digit_sum_prefix[i - 1] + digit;
            count_prefix[i] = count_prefix[i - 1] + (digit > 0 ? 1 : 0);
            
            if (digit > 0) {
                concat_prefix[i] = (concat_prefix[i - 1] * 10 + digit) % MOD;
            } else {
                concat_prefix[i] = concat_prefix[i - 1];
            }
        }
        
        vector<int> ans;
        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            int k = count_prefix[r + 1] - count_prefix[l];
            int current_sum = digit_sum_prefix[r + 1] - digit_sum_prefix[l];
            
            long long x = (concat_prefix[r + 1] - (concat_prefix[l] * pow10[k]) % MOD + MOD) % MOD;
            ans.push_back((x * current_sum) % MOD);
        }
        
        return ans;
    }
};