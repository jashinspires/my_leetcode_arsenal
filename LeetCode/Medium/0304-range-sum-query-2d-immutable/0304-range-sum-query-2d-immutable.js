/**
 * @param {number[][]} matrix
 */
var NumMatrix = function(matrix) {
    if (!matrix || matrix.length === 0 || matrix[0].length === 0) return;

    const n = matrix.length;
    const m = matrix[0].length;

    // Initialize (n + 1) x (m + 1) 2D array filled with 0s
    this.pfm = Array.from({ length: n + 1 }, () => Array(m + 1).fill(0));

    for (let i = 1; i <= n; i++) {
        for (let j = 1; j <= m; j++) {
            this.pfm[i][j] =
                matrix[i - 1][j - 1] +
                this.pfm[i - 1][j] +
                this.pfm[i][j - 1] -
                this.pfm[i - 1][j - 1];
        }
    }
};

/** 
 * @param {number} row1 
 * @param {number} col1 
 * @param {number} row2 
 * @param {number} col2
 * @return {number}
 */
NumMatrix.prototype.sumRegion = function(row1, col1, row2, col2) {
    return (
        this.pfm[row2 + 1][col2 + 1] -
        this.pfm[row1][col2 + 1] -
        this.pfm[row2 + 1][col1] +
        this.pfm[row1][col1]
    );
};

/** 
 * Your NumMatrix object will be instantiated and called as such:
 * var obj = new NumMatrix(matrix)
 * var param_1 = obj.sumRegion(row1,col1,row2,col2)
 */