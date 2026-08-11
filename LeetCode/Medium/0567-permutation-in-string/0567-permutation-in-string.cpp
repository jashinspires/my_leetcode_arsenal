class Solution {
public:
    bool checkInclusion(string s1, string s2){
        if(s1.size() > s2.size()) return false;
        vector<int> s1freq(26,0);
        vector<int> s2freq(26,0);
        int s1_size = s1.size();
        for(int i = 0 ; i < s1_size ; i++ ){
            s1freq[s1[i] - 'a']++;
        }
        for(int j = 0 ; j < s1_size ; j++){
            s2freq[s2[j] - 'a']++;
        }
        if(s1freq == s2freq) return true;
        for(int i = 1; i <= s2.size() - s1_size ; i++){
            s2freq[s2[i-1] - 'a']--;
            s2freq[s2[s1_size - 1 + i] - 'a']++;
            if(s2freq == s1freq) return true;
        }
        return false;

    }
};