class Solution {
public:
    int numberOfSubstrings(string s) {
        int counts[3] = {0, 0, 0};
        int ans = 0;
        int left = 0;
        int n = s.length();

        for (int right = 0; right < n; ++right) {
            counts[s[right] - 'a']++;
            
            while (counts[0] > 0 && counts[1] > 0 && counts[2] > 0) {
                ans += n - right;
                counts[s[left] - 'a']--;
                left++;
            }
        }
        
        return ans;
    }
};