class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //optimal approach
        int rows = matrix.size();
        int columns = matrix[0].size();
        bool rmarked = false;
        bool cmarked = false;
        for(int r = 0 ; r < columns ; r++){
            if(matrix[0][r] == 0){
                rmarked = true;
                break;
            }
        }

        for(int c = 0 ; c < rows ; c++){
            if(matrix[c][0] == 0){
                cmarked = true;
                break;
            }
        }
        for(int r = 0 ; r < rows ; r++){
            for(int c = 0 ; c < columns ; c++){
                if(matrix[r][c] == 0){
                    matrix[r][0] = 0 ;
                    matrix[0][c] = 0;
                }
            }
        }
        for(int r = 1 ; r < rows ; r ++){
            for(int c = 1 ; c < columns ; c++){
                if(matrix[r][0] == 0 || matrix[0][c] == 0){
                    matrix[r][c] = 0;
                }
            }
        }

        if(rmarked){
            for(int r = 0 ; r < columns ; r++){
                matrix[0][r] = 0;
            }
        }

        if(cmarked){
            for(int c = 0 ; c < rows ; c++){
                matrix[c][0] = 0;
            }
        }
    }
};