class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int totalLength = s.length();

        if (s[totalLength - 1] != '0') {
            return false;
        }

        vector<bool> trackReachable(totalLength, false);
        trackReachable[0] = true;

        int availableJumpsInWindow = 0;

        for (int currentIndex = 1; currentIndex < totalLength; ++currentIndex) {
            if (currentIndex >= minJump) {
                if (trackReachable[currentIndex - minJump]) {
                    availableJumpsInWindow++;
                }
            }

            if (currentIndex > maxJump) {
                if (trackReachable[currentIndex - maxJump - 1]) {
                    availableJumpsInWindow--;
                }
            }

            if (availableJumpsInWindow > 0 && s[currentIndex] == '0') {
                trackReachable[currentIndex] = true;
            }
        }

        return trackReachable[totalLength - 1];
    }
};