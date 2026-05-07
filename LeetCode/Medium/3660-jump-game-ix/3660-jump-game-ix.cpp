#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};
        vector<int> prefixMax(n);
        prefixMax[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(prefixMax[i - 1], nums[i]);
        }
        
        vector<int> suffixMin(n);
        suffixMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(suffixMin[i + 1], nums[i]);
        }
        
        vector<int> ans(n);
        int start = 0;
    
        for (int i = 0; i < n; i++) {
            if (i == n - 1 || prefixMax[i] <= suffixMin[i + 1]) {
                int blockMax = prefixMax[i]; 
                for (int j = start; j <= i; j++) {
                    ans[j] = blockMax;
                }
                start = i + 1;
            }
        }
        
        return ans;
    }
};