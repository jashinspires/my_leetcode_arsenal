#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
private:
    int get_lca(int u, int v, const vector<int>& depth, const vector<vector<int>>& up) {
        if (depth[u] < depth[v]) {
            swap(u, v);
        }
        int diff = depth[u] - depth[v];
        for (int j = 17; j >= 0; --j) {
            if ((diff >> j) & 1) {
                u = up[u][j];
            }
        }
        if (u == v) return u;
        for (int j = 17; j >= 0; --j) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }
        return up[u][0];
    }

public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> depth(n + 1, 0);
        vector<vector<int>> up(n + 1, vector<int>(18, 0));
        vector<bool> visited(n + 1, false);

        queue<int> q;
        q.push(1);
        visited[1] = true;
        depth[1] = 0;
        up[1][0] = 1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    depth[v] = depth[u] + 1;
                    up[v][0] = u;
                    q.push(v);
                }
            }
        }

        for (int j = 1; j < 18; ++j) {
            for (int i = 1; i <= n; ++i) {
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }

        const int MOD = 1e9 + 7;
        vector<int> pow2(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }

        vector<int> ans;
        ans.reserve(queries.size());
        for (const auto& query : queries) {
            int u = query[0];
            int v = query[1];
            if (u == v) {
                ans.push_back(0);
            } else {
                int lca = get_lca(u, v, depth, up);
                int k = depth[u] + depth[v] - 2 * depth[lca];
                ans.push_back(pow2[k - 1]);
            }
        }

        return ans;
    }
};