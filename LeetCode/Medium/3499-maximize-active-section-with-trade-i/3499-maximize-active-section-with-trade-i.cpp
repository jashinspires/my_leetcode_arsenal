class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int totalOnes = 0;

        for (char ch : s) {
            if (ch == '1') {
                totalOnes++;
            }
        }

        string augmented = "1" + s + "1";

        vector<pair<char, int>> groups;

        for (char ch : augmented) {
            if (groups.empty() || groups.back().first != ch) {
                groups.push_back({ch, 1});
            } else {
                groups.back().second++;
            }
        }

        int maximumGain = 0;
        for (int i = 1; i + 1 < groups.size(); i++) {
            bool isValidTrade =
                groups[i - 1].first == '0' &&
                groups[i].first == '1' &&
                groups[i + 1].first == '0';

            if (isValidTrade) {
                int leftZeros = groups[i - 1].second;
                int rightZeros = groups[i + 1].second;

                maximumGain = max(
                    maximumGain,
                    leftZeros + rightZeros
                );
            }
        }

        return totalOnes + maximumGain;
    }
};