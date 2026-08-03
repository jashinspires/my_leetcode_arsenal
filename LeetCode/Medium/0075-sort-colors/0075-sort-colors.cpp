class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> count(3);
        for(int n : nums){
            if(n == 0){
                count[0] += 1;
            }else if(n == 1){
                count[1] += 1;
            }else if(n == 2){
                count[2] += 1;
            }
        }
        int i = 0;
        for(int c = 0 ; c < count.size() ; c++){
            int val = count[c];
            while(val > 0){
                nums[i] = c;
                i++;
                val--;
            }
        }
    }
};