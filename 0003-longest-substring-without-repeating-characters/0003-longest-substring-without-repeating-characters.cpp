class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int n = s.size();
       int max_len = 0;
       for(int i = 0 ; i < n ; i++){
        vector<int> hash(256,0);
        for(int j = i ; j < n ; j++){
            if(hash[s[j]] == 1) break;
            int len = j - i + 1;
            max_len = max(len , max_len);
            hash[s[j]]++;
        }
       }
       return max_len;
    }
};