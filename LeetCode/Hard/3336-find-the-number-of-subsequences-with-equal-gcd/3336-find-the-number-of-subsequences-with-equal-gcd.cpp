#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
    static constexpr int MOD = 1000000007;
    static constexpr int LIM = 201;
    int mu[LIM];
    int pow2[LIM], pow3[LIM];

    void init() {
        pow2[0] = pow3[0] = 1;
        for (int i = 1; i < LIM; i++) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
            pow3[i] = ((long long)pow3[i - 1] * 3) % MOD;
        }
        std::fill(mu, mu + LIM, 0);
        mu[1] = 1;
        for (int i = 1; i < LIM; i++) {
            for (int j = i * 2; j < LIM; j += i) {
                mu[j] -= mu[i];
            }
        }
    }

public:
    int subsequencePairCount(std::vector<int>& nums) {
        init();
        int mx = *std::max_element(nums.begin(), nums.end());
        std::vector<int> count(mx + 1, 0);
        for (int n : nums) {
            count[n]++;
        }
        for (int i = 1; i <= mx; i++) {
            for (int j = i * 2; j <= mx; j += i) {
                count[i] += count[j];
            }
        }

        std::vector<std::vector<int>> dp(mx + 1, std::vector<int>(mx + 1, 0));
        for (int i = 1; i <= mx; i++) {
            for (int j = 1; j <= mx; j++) {
                int g = std::gcd(i, j);
                long long l = ((long long)i * j) / g;
                int c = (l <= mx) ? count[l] : 0;
                int ci = count[i];
                int cj = count[j];

                long long term1 = ((long long)pow3[c] * pow2[ci + cj - c * 2]) % MOD;
                long long val = (term1 - pow2[ci] - pow2[cj] + 1) % MOD;
                dp[i][j] = (val + MOD) % MOD;
            }
        }

        long long res = 0;
        for (int i = 1; i <= mx; i++) {
            for (int j = 1; j <= mx / i; j++) {
                for (int k = 1; k <= mx / i; k++) {
                    long long term = (((long long)mu[j] * mu[k]) % MOD * dp[j * i][k * i]) % MOD;
                    res = (res + term) % MOD;
                }
            }
        }

        return (res + MOD) % MOD;
    }
};