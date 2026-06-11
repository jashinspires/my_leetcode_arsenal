#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    struct RH {
        int l = 0, s = 0;
        vector<pair<int, int>> b[33];
        void push(int k, int v) {
            b[k == l ? 0 : 32 - __builtin_clz(k ^ l)].push_back({k, v});
            s++;
        }
        pair<int, int> pop() {
            if (b[0].empty()) {
                int i = 1;
                while (b[i].empty()) i++;
                int m = b[i][0].first;
                for (auto& p : b[i]) m = min(m, p.first);
                l = m;
                vector<pair<int, int>> t;
                t.swap(b[i]);
                for (auto& p : t) {
                    b[p.first == l ? 0 : 32 - __builtin_clz(p.first ^ l)].push_back(p);
                }
            }
            auto r = b[0].back();
            b[0].pop_back();
            s--;
            return r;
        }
        bool empty() { return s == 0; }
    };

public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> g(n + 1);
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<int> d(n + 1, -1);
        RH h;
        d[1] = 0;
        h.push(0, 1);
        int mx = 0;
        while (!h.empty()) {
            auto [cw, u] = h.pop();
            if (cw > d[u]) continue;
            mx = max(mx, cw);
            for (int v : g[u]) {
                if (d[v] == -1 || d[u] + 1 < d[v]) {
                    d[v] = d[u] + 1;
                    h.push(d[v], v);
                }
            }
        }
        long long ans = 1;
        for (int i = 0; i < mx - 1; ++i) {
            ans = (ans * 2) % 1000000007;
        }
        return ans;
    }
};