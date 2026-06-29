class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0 ;
        for ( const std::string &a :patterns ){
            if (word.find(a) != std::string::npos){
                count +=1 ;
            }
        }
        return count;
    }
};