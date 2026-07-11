class Solution {
public:
    void dfs(int u, const vector<vector<int>>& adj, vector<bool>& vis, int& nodes, int& edges) {
        vis[u] = true;
        nodes++;
        edges += adj[u].size();
        for (int v : adj[u]) {
            if (!vis[v]) {
                dfs(v, adj, vis, nodes, edges);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int nodes = 0, edge_count = 0;
                dfs(i, adj, vis, nodes, edge_count);
                if (edge_count == nodes * (nodes - 1)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};