class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size(), MOD = 1e9 + 7;
        vector<vector<int>> mx(n + 1, vector<int>(n + 1, -1));
        vector<vector<int>> ct(n + 1, vector<int>(n + 1, 0));
        
        mx[n-1][n-1] = 0;
        ct[n-1][n-1] = 1;
        
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (board[i][j] == 'X' || (i == n - 1 && j == n - 1)) continue;
                
                int r1 = mx[i+1][j], r2 = mx[i][j+1], r3 = mx[i+1][j+1];
                int cur_mx = max({r1, r2, r3});
                
                if (cur_mx == -1) continue;
                
                mx[i][j] = cur_mx + (board[i][j] == 'E' ? 0 : board[i][j] - '0');
                
                long long cur_ct = 0;
                if (r1 == cur_mx) cur_ct += ct[i+1][j];
                if (r2 == cur_mx) cur_ct += ct[i][j+1];
                if (r3 == cur_mx) cur_ct += ct[i+1][j+1];
                
                ct[i][j] = cur_ct % MOD;
            }
        }
        
        return {max(0, mx[0][0]), ct[0][0]};
    }
};