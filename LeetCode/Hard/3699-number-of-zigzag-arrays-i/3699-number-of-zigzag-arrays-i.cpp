class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int k =  r-l+1;
        const int MOD = 1000000007;
        vector<int> u(k+2,0), v(k+2,0);
        for(int j = 1 ; j <= k; ++j) u[j] = j - 1;
        for(int i = 3; i <= n; ++i) {
            int s = 0 ; 
            for(int j = 1 ; j <=k ; ++j){
                v[j] = s;
                s += u[k - j + 1];
                if (s >= MOD) s -= MOD;
            }
            u.swap(v);
        }
        int a = 0 ;
        for(int j = 1 ; j <= k ; ++j){
            a += u[j];
            if(a >= MOD) a -= MOD;
        }
        a *= 2;
        if(a >= MOD) a -= MOD;
        return a;
    }
};