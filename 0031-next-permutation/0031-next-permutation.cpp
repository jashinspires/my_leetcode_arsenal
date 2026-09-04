class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot = -1;
        int s = (int)nums.size() - 1;
        if (s + 1 == 2) {
            swap(nums[0], nums[1]);
        }
        if (s + 1 > 2) {
            for (int i = (int)nums.size() - 2; i >= 0; i--) {
                if (nums[i] < nums[i + 1]) {
                    pivot = i;
                    break;
                }
            }
            if (pivot == -1) {
                int left = 0;
                int right = s;
                while (left <= right) {
                    swap(nums[left], nums[right]);
                    left++;
                    right--;
                }
            } else {
                int next_greater = -1;
                for (int i = s; i > pivot; i--) {
                    if (nums[i] > nums[pivot]) {
                        next_greater = i;
                        break;
                    }
                }
                swap(nums[pivot], nums[next_greater]);
                int left = pivot + 1;
                int right = nums.size() - 1;
                while (left <= right) {
                    swap(nums[left], nums[right]);
                    left++;
                    right--;
                }
            }
        }
    }
};