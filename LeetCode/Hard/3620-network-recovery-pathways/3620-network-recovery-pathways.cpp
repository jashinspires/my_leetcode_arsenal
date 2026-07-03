#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& E, vector<bool>& O, long long k) {
        int n = O.size();
        vector<vector<pair<int, int>>> g(n);
        int mx = 0;
        for (auto& e : E) {
            g[e[0]].push_back({e[1], e[2]});
            mx = max(mx, e[2]);
        }

        auto check = [&](int m) {
            vector<long long> D(n, -1);
            priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
            D[0] = 0;
            q.push({0, 0});
            while (!q.empty()) {
                auto [d, u] = q.top();
                q.pop();
                if (d > D[u]) continue;
                if (u == n - 1) return d <= k;
                for (auto& [v, c] : g[u]) {
                    if (!O[v] || c < m) continue;
                    if (D[v] == -1 || d + c < D[v]) {
                        D[v] = d + c;
                        q.push({D[v], v});
                    }
                }
            }
            return D[n - 1] != -1 && D[n - 1] <= k;
        };

        int l = 0, r = mx, ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};