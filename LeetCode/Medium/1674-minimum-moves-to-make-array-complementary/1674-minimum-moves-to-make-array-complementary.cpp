class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> diff(2 * limit + 2, 0);
        
        for (int i = 0; i < n / 2; ++i) {
            int A = min(nums[i], nums[n - 1 - i]);
            int B = max(nums[i], nums[n - 1 - i]);
            
            diff[2] += 2;
            diff[A + 1] -= 1;
            diff[A + B] -= 1;
            diff[A + B + 1] += 1;
            diff[B + limit + 1] += 1;
        }
        
        int min_moves = n;
        int current_moves = 0;
        
        for (int T = 2; T <= 2 * limit; ++T) {
            current_moves += diff[T];
            min_moves = min(min_moves, current_moves);
        }
        
        return min_moves;
    }
};