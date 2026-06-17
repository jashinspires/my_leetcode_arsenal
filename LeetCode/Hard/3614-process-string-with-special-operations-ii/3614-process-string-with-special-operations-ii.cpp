class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.length();
        vector<long long> v(n, 0);
        long long len = 0;

        for (int i = 0; i < n; ++i) {
            if (s[i] == '*') {
                if (len > 0) len--;
            } else if (s[i] == '#') {
                len *= 2;
            } else if (s[i] == '%') {

            } else {
                len++;
            }
            v[i] = len;
        }

        if (k >= len) return '.';

        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '*') {
                continue;
            } else if (s[i] == '#') {
                long long p = (i > 0) ? v[i - 1] : 0;
                if (k >= p) k %= p;
            } else if (s[i] == '%') {
                k = v[i] - 1 - k;
            } else {
                long long p = (i > 0) ? v[i - 1] : 0;
                if (k == p) return s[i];
            }
        }

        return '.';
    }
};