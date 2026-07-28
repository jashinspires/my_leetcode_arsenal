#include <string>
#include <algorithm>

class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        int half_len = n / 2;
        string half = s.substr(0, half_len);
        sort(half.begin(), half.end());
        string rev_half = half;
        reverse(rev_half.begin(), rev_half.end());
        if (n % 2 == 1) {
            return half + s[half_len] + rev_half;
        } else {
            return half + rev_half;
        }
    }
};