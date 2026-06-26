#include <vector>

using namespace std;

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> bit(2 * n + 2, 0);
        
        auto update = [&](int idx, int val) {
            for (; idx < bit.size(); idx += idx & -idx) {
                bit[idx] += val;
            }
        };
        
        auto query = [&](int idx) {
            int sum = 0;
            for (; idx > 0; idx -= idx & -idx) {
                sum += bit[idx];
            }
            return sum;
        };
        
        long long ans = 0;
        int pref = 0;
        
        update(0 + n + 1, 1);
        
        for (int x : nums) {
            if (x == target) {
                pref += 1;
            } else {
                pref -= 1;
            }
            ans += query(pref + n);
            update(pref + n + 1, 1);
        }
        
        return ans;
    }
};