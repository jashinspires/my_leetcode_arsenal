class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (m == 1 && n == 1)
            return true;
        vector<vector<int>> dirs = {{},     {2, 3}, {0, 1}, {2, 1},
                                    {3, 1}, {2, 0}, {3, 0}};
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        int opp[4] = {1, 0, 3, 2};
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0][0] = true;
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            int type = grid[r][c];
            for (int d : dirs[type]) {
                int nr = r + dr[d];
                int nc = c + dc[d];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n || vis[nr][nc])
                    continue;
                int ntype = grid[nr][nc];
                bool connected = false;
                for (int nd : dirs[ntype]) {
                    if (nd == opp[d]) {
                        connected = true;
                        break;
                    }
                }
                if (connected) {
                    if (nr == m - 1 && nc == n - 1)
                        return true;
                    vis[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
        return false;
    }
};