class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int mx = 0;
        for (int c : costs) {
            if (c > mx) mx = c;
        }
        
        vector<int> cnt(mx + 1, 0);
        for (int c : costs) {
            cnt[c]++;
        }
        
        int res = 0;
        for (int i = 1; i <= mx; ++i) {
            if (cnt[i] == 0) continue;
            if (coins < i) break;
            
            int take = min(cnt[i], coins / i);
            res += take;
            coins -= take * i;
        }
        
        return res;
    }
};