class NumMatrix {
private:
    vector<vector<int>> pfm;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        pfm.assign(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                pfm[i][j] =
                    matrix[i - 1][j - 1]
                    + pfm[i - 1][j]
                    + pfm[i][j - 1]
                    - pfm[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return pfm[row2 + 1][col2 + 1]
             - pfm[row1][col2 + 1]
             - pfm[row2 + 1][col1]
             + pfm[row1][col1];
    }
};