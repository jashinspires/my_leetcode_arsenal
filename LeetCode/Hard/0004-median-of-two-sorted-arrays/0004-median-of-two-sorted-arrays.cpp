class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end() , nums2.begin() , nums2.end());
        sort(nums1.begin() , nums1.end());
        int s = nums1.size() ;
        int m = s/2;
        double val ;
        if(s%2 == 0){
             val = (double)(nums1[m] + nums1[m-1])/2;
        }else val = nums1[m];
    return val;
}

};