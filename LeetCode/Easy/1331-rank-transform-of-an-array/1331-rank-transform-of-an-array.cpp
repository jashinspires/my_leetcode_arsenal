class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.empty()) return {};

        vector<pair<int, int>> indexedArr;
        indexedArr.reserve(arr.size());
        for (int i = 0; i < arr.size(); ++i) {
            indexedArr.push_back({arr[i], i});
        }

        sort(indexedArr.begin(), indexedArr.end());

        vector<int> ranks(arr.size());
        int rank = 1;
        ranks[indexedArr[0].second] = rank;

        for (int i = 1; i < indexedArr.size(); ++i) {
            if (indexedArr[i].first > indexedArr[i - 1].first) {
                rank++;
            }
            ranks[indexedArr[i].second] = rank;
        }

        return ranks;
    }
};