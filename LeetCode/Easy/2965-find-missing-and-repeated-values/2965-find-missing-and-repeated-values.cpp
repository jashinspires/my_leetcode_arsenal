class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int,int> count;
        int n = grid.size();
        int summ = (n*n)*((n*n) + 1)/2;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                count[grid[i][j]]++;
            }
        }
        int s2 = 0;
        int r = 0;
        for(const auto& [k,v] : count){
                s2 += k;
                if( v == 2){
                    r = k;
                }
            
        }
        return {r,summ - s2};
    }
};