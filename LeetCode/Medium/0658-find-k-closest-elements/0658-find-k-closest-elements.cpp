class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int s = arr.size();
        int left = 0;
        int right = s - 1;
        while((right - left + 1) > k){
            if(abs(arr[left]-x) > abs(arr[right]-x)){
                left++;
            }else{
                right--;
            }
        }
        vector<int> result(arr.begin() + left, arr.begin() + right + 1);
        return result;

    }
};