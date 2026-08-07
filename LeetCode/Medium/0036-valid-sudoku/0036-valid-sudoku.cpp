class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9] , cols[9] , boxes[9];
        for(int r = 0 ; r < 9 ; r++){
            for(int c = 0 ; c < 9 ; c++){
                char v = board[r][c];
                if(v == '.') continue;
                int b = (r/3)*3 + (c/3);
                if(rows[r].count(v) || cols[c].count(v) || boxes[b].count(v)) return false;
                rows[r].insert(v);
                cols[c].insert(v);
                boxes[b].insert(v);
            }
        }
        return true;
    }
};