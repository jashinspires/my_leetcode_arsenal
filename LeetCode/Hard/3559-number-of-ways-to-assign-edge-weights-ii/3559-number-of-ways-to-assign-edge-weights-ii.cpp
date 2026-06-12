#include <vector>
#include <numeric>
#include <utility>

using namespace std;

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
private:
    int n;
    vector<vector<int>> g;
    vector<vector<pair<int, int>>> q;
    vector<int> lca_ans, deep, uf;
    vector<bool> vis;

    int find(int x) {
        while (uf[x] != x) {
            uf[x] = uf[uf[x]];
            x = uf[x];
        }
        return x;
    }

    void tarjan(int u, int parent, int d) {
        vis[u] = true;
        deep[u] = d;
        for (int v : g[u]) {
            if (v == parent) continue;
            tarjan(v, u, d + 1);
            uf[v] = u;
        }
        for (auto [node, idx] : q[u]) {
            if (vis[node]) {
                lca_ans[idx] = find(node);
            }
        }
    }

public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        n = edges.size() + 1;
        g.assign(n + 1, {});
        q.assign(n + 1, {});
        lca_ans.assign(queries.size(), 0);
        deep.assign(n + 1, 0);
        uf.resize(n + 1);
        iota(uf.begin(), uf.end(), 0);
        vis.assign(n + 1, false);

        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        for (int i = 0; i < (int)queries.size(); i++) {
            q[queries[i][0]].emplace_back(queries[i][1], i);
            q[queries[i][1]].emplace_back(queries[i][0], i);
        }

        tarjan(1, 0, 0);

        const int MOD = 1e9 + 7;
        vector<int> pow2(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }

        vector<int> ans(queries.size());
        for (int i = 0; i < (int)queries.size(); i++) {
            int x = deep[queries[i][0]] + deep[queries[i][1]] - 2 * deep[lca_ans[i]];
            ans[i] = (x == 0) ? 0 : pow2[x - 1];
        }
        return ans;
    }
};