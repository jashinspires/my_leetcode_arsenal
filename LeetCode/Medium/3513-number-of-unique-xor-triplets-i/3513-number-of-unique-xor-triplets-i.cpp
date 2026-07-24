class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
          int n = nums.size();
        if (n == 1) return 1;
        if (n == 2) return 2;

        int p = 1;
        while (p * 2 <= n) {
            p *= 2;
        }
        return p * 2;
    }
};