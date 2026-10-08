class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int columns = matrix[0].size();
        vector<bool> r0(rows,false);
        vector<bool> c0(columns,false); 
        for(int r = 0 ; r < rows ; r++){
            for(int c = 0 ; c < columns ; c++){
                if(matrix[r][c] == 0){
                    r0[r] = true;
                    c0[c] = true;
                }
            }
        }
         for(int r = 0 ; r < rows ; r++){
            for(int c = 0 ; c < columns ; c++){
                if(r0[r] == true || c0[c] == true){
                    matrix[r][c] = 0;
                }
            }
        }
    }
};