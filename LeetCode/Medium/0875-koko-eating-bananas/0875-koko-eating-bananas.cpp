class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        int ans = high;
        while(low <= high){
            int mid = low + (high - low)/2;
            long long totalHours = 0;
            for(int pile : piles){
                totalHours += (pile + (long long)mid - 1)/mid ;
            }
            if(totalHours <= h){
                ans = mid;
                high = mid-1;
            }else {
                low = mid + 1;
            }
        }
        return ans;
    }
};