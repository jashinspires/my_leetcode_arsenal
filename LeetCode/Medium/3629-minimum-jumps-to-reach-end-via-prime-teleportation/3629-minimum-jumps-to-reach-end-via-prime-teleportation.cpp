#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
    static const int MAXV = 1000001;
    static int spf[MAXV];
    static bool seeded;

    void sieve() {
        if (seeded) return;
        for (int i = 2; i < MAXV; ++i) {
            if (spf[i] == 0) {
                for (int j = i; j < MAXV; j += i) {
                    if (spf[j] == 0) spf[j] = i;
                }
            }
        }
        seeded = true;
    }

public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        sieve();

        int max_val = 0;
        for (int x : nums) if (x > max_val) max_val = x;

        vector<vector<int>> multiples(max_val + 1);
        for (int i = 0; i < n; ++i) {
            int val = nums[i];
            while (val > 1) {
                int p = spf[val];
                multiples[p].push_back(i);
                while (val % p == 0) val /= p;
            }
        }

        vector<int> dist(n, -1);
        vector<bool> prime_used(max_val + 1, false);
        queue<int> q;

        q.push(0);
        dist[0] = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (u == n - 1) return dist[u];

            if (u + 1 < n && dist[u + 1] == -1) {
                dist[u + 1] = dist[u] + 1;
                q.push(u + 1);
            }
            if (u - 1 >= 0 && dist[u - 1] == -1) {
                dist[u - 1] = dist[u] + 1;
                q.push(u - 1);
            }

            int p = nums[u];
            if (p > 1 && p <= max_val && spf[p] == p && !prime_used[p]) {
                prime_used[p] = true;
                for (int v : multiples[p]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
            }
        }

        return -1;
    }
};
int Solution::spf[MAXV] = {0};
bool Solution::seeded = false;