class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> parent(m * n);
        vector<int> rank(m * n, 0);
        for (int i = 0; i < m * n; ++i) parent[i] = i;
        function<int(int)> find = [&](int x) {
            if (parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        };
        auto unite = [&](int x, int y) {
            int px = find(x), py = find(y);
            if (px == py) return false;
            if (rank[px] < rank[py]) parent[px] = py;
            else if (rank[px] > rank[py]) parent[py] = px;
            else { parent[py] = px; rank[px]++; }
            return true;
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j + 1 < n && grid[i][j] == grid[i][j+1]) {
                    if (!unite(i * n + j, i * n + j + 1)) return true;
                }
                if (i + 1 < m && grid[i][j] == grid[i+1][j]) {
                    if (!unite(i * n + j, (i + 1) * n + j)) return true;
                }
            }
        }
        return false;
    }
};