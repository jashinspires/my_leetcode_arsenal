class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        sort(people.begin(),people.end());
        int left = 0 ;
        int total_boats = 0;
        int right = people.size() - 1;
        while(left <= right){
            if(people[left] + people[right] <= limit){
                total_boats++;
                left++;
                right--;
            }else if(people[right] + people[left] > limit){
                total_boats++;
                right--;
            }
        }
        return total_boats;
    }
};