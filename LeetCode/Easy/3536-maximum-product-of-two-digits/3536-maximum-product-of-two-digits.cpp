class Solution {
public:
    int maxProduct(int n) {
        string nums = to_string(n);
        int max1 = 0, max2 = 0;
        
        for (char ch : nums) {
            int val = ch - '0';
            if (val > max1) {
                max2 = max1;
                max1 = val;
            } else if (val > max2) {
                max2 = val;
            }
        }
        return max1 * max2;
    }
};