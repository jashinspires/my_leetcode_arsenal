class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& g, int h) {
        int n = g.size(), m = g[0].size();
        vector<vector<int>> d(n, vector<int>(m, INT_MAX));
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        d[0][0] = g[0][0];
        pq.emplace(g[0][0], 0, 0);
        const int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
        while(!pq.empty()) {
            auto [c,x,y] = pq.top(); pq.pop();
            if(c > d[x][y]) continue;
            if(x == n-1 && y == m-1) return c < h;
            for(int k = 0; k < 4; ++k) {
                int nx = x + dx[k], ny = y + dy[k];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int nc = c + g[nx][ny];
                    if(nc < d[nx][ny]) {
                        d[nx][ny] = nc;
                        pq.emplace(nc, nx, ny);
                    }
                }
            }
        }
        return false;
    }
};