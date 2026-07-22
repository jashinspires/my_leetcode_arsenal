#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    struct Segment {
        int start;
        int end;
        int type;
    };

    int querySparseTable(const vector<vector<int>>& sparseTable, const vector<int>& logTable, int left, int right) {
        if (left > right) {
            return 0;
        }
        int length = right - left + 1;
        int power = logTable[length];
        return max(sparseTable[power][left], sparseTable[power][right - (1 << power) + 1]);
    }

public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        int totalOnes = 0;
        for (char charVal : s) {
            if (charVal == '1') {
                totalOnes++;
            }
        }

        vector<Segment> segments;
        int segmentStart = 0;
        for (int i = 0; i < n; i++) {
            if (i == n - 1 || s[i] != s[i + 1]) {
                segments.push_back({segmentStart, i, s[i] - '0'});
                segmentStart = i + 1;
            }
        }

        int segmentCount = segments.size();
        vector<int> oneSegmentIndices;
        for (int i = 0; i < segmentCount; i++) {
            if (segments[i].type == 1) {
                oneSegmentIndices.push_back(i);
            }
        }

        int numOnes = oneSegmentIndices.size();
        vector<int> gainValues(numOnes, 0);
        for (int i = 0; i < numOnes; i++) {
            int segIdx = oneSegmentIndices[i];
            if (segIdx - 1 >= 0 && segIdx + 1 < segmentCount) {
                gainValues[i] = (segments[segIdx - 1].end - segments[segIdx - 1].start + 1) +
                                (segments[segIdx + 1].end - segments[segIdx + 1].start + 1);
            }
        }

        vector<int> logTable(numOnes + 1, 0);
        for (int i = 2; i <= numOnes; i++) {
            logTable[i] = logTable[i / 2] + 1;
        }

        int maxLog = logTable[numOnes] + 1;
        vector<vector<int>> sparseTable(maxLog, vector<int>(numOnes, 0));
        for (int i = 0; i < numOnes; i++) {
            sparseTable[0][i] = gainValues[i];
        }

        for (int j = 1; j < maxLog; j++) {
            for (int i = 0; i + (1 << j) <= numOnes; i++) {
                sparseTable[j][i] = max(sparseTable[j - 1][i], sparseTable[j - 1][i + (1 << (j - 1))]);
            }
        }

        auto computeGain = [&](int segIdx, int leftBound, int rightBound) -> int {
            if (segIdx - 1 < 0 || segIdx + 1 >= segmentCount) {
                return 0;
            }
            const auto& leftSeg = segments[segIdx - 1];
            const auto& rightSeg = segments[segIdx + 1];

            if (leftSeg.end < leftBound || rightSeg.start > rightBound) {
                return 0;
            }

            int zeroCountLeft = leftSeg.end - max(leftSeg.start, leftBound) + 1;
            int zeroCountRight = min(rightSeg.end, rightBound) - rightSeg.start + 1;
            return zeroCountLeft + zeroCountRight;
        };

        vector<int> results;
        results.reserve(queries.size());

        for (const auto& query : queries) {
            int leftBound = query[0];
            int rightBound = query[1];

            int low = 0, high = numOnes - 1;
            int firstOneIndex = -1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (segments[oneSegmentIndices[mid]].start >= leftBound) {
                    firstOneIndex = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            low = 0;
            high = numOnes - 1;
            int lastOneIndex = -1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (segments[oneSegmentIndices[mid]].end <= rightBound) {
                    lastOneIndex = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            if (firstOneIndex == -1 || lastOneIndex == -1 || firstOneIndex > lastOneIndex) {
                results.push_back(totalOnes);
                continue;
            }

            int bestGain = 0;
            int firstSegIdx = oneSegmentIndices[firstOneIndex];
            int lastSegIdx = oneSegmentIndices[lastOneIndex];

            bestGain = max(bestGain, computeGain(firstSegIdx, leftBound, rightBound));
            bestGain = max(bestGain, computeGain(lastSegIdx, leftBound, rightBound));

            if (firstOneIndex + 1 <= lastOneIndex - 1) {
                bestGain = max(bestGain, querySparseTable(sparseTable, logTable, firstOneIndex + 1, lastOneIndex - 1));
            }

            results.push_back(totalOnes + bestGain);
        }

        return results;
    }
};