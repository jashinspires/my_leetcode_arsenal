class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<pair<char, int>> runlength;
        char current_char = s[0];
        int lengthofseq = 0;
        for (char ch : s) {
            if (ch != current_char) {
                runlength.push_back({current_char, lengthofseq});
                current_char = ch;
                lengthofseq = 1;
            } else {
                lengthofseq++;
            }
        }
        runlength.push_back({current_char, lengthofseq});
        int gain = 0;
        int totalones = 0;
        int rl = runlength.size();
        for (const auto& p : runlength) {
            if (p.first == '1') {
                totalones += p.second;
            }
        }
        for (int i = 1; i < rl - 1; i++) {
            if (runlength[i].first == '1') {
                int c = runlength[i - 1].second + runlength[i + 1].second;
                gain = max(gain, c);
            }
        }
        return gain + totalones;
    }
};