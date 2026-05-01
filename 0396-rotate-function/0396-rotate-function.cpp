class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long n = nums.size(), s = 0, f = 0, m;
        for (long i = 0; i < n; ++i) {
            s += nums[i];
            f += i * nums[i];
        }
        m = f;
        for (long i = n - 1; i > 0; --i) {
            f += s - n * nums[i];
            if (f > m) m = f;
        }
        return m;
    }
};