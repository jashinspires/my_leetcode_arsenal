class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const int M = 1e9+7;
        int k = r - l + 1, s = 2*k;
        if (n == 1) return k;
        if (n == 2) return (long long)k*(k-1)%M;
        vector<vector<long long>> T(s, vector<long long>(s));
        for (int i=0; i<k; ++i) {
            for (int j=0; j<i; ++j) T[j*2+1][i*2] = 1;
            for (int j=i+1; j<k; ++j) T[j*2][i*2+1] = 1;
        }
        vector<long long> v(s);
        for (int i=0; i<k; ++i) v[i*2]=i, v[i*2+1]=k-1-i;
        auto mul = [&](const vector<vector<long long>>& A, const vector<vector<long long>>& B) {
            int m = A.size();
            vector<vector<long long>> C(m, vector<long long>(m));
            for (int i=0; i<m; ++i)
                for (int k=0; k<m; ++k) if (A[i][k])
                    for (int j=0; j<m; ++j)
                        C[i][j] = (C[i][j] + A[i][k]*B[k][j]) % M;
            return C;
        };
        auto pw = [&](vector<vector<long long>> A, long long p) {
            int m = A.size();
            vector<vector<long long>> R(m, vector<long long>(m));
            for (int i=0; i<m; ++i) R[i][i]=1;
            for (; p; p>>=1) {
                if (p&1) R = mul(A, R);
                A = mul(A, A);
            }
            return R;
        };
        auto Tn = pw(T, n-2);
        long long ans = 0;
        for (int i=0; i<s; ++i)
            for (int j=0; j<s; ++j)
                ans = (ans + v[j]*Tn[i][j]) % M;
        return ans;
    }
};