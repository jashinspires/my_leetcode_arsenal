class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numbers(nums.begin(), nums.end());
        int longestLength = 0;
        for (int x : numbers) {
            if (numbers.find(x - 1) == numbers.end()) {
                int currentNumber = x;
                int currentLength = 1;
                while (numbers.find(currentNumber + 1) != numbers.end()) {
                    currentNumber++;
                    currentLength++;
                }
                longestLength = max(longestLength, currentLength);
            }
        }
        return longestLength;
    }
};