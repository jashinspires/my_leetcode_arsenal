class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_ = 0;
        int left = 0 ;
        int right = height.size()-1;
        while(left < right){
            if(height[right] < height[left]){
                max_ = max(max_,height[right]*(right - left));
                right--;
            }else if(height[left] < height[right]){
                max_ = max(max_,height[left]*(right - left));
                left++;
            } else if(height[left] == height[right]){
                max_ = max(max_,height[left]*(right - left));
                left++;
                right--;
            }
        }
        return max_;
    }
};