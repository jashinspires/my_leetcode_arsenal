class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> output;
        int left = 0 ;
        int right = numbers.size() - 1;
        while(left < right){
            if(numbers[left] + numbers[right] < target){
                left++;
            }else if(numbers[left] + numbers[right] > target){
                right--;
            }else if(numbers[left] + numbers[right] == target){
                return {left+1,right+1};
            }
        }
        return output;
    }
};