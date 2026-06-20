class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        vector<pair<int, long long>> r = {{1, 0}, {n, (long long)n}};
        for (auto& x : restrictions)
            r.push_back({x[0], x[1]});
        sort(r.begin(), r.end());
        int m = r.size();
        for (int i = 1; i < m; ++i)
            r[i].second =
                min(r[i].second, r[i - 1].second + r[i].first - r[i - 1].first);
        for (int i = m - 2; i >= 0; --i)
            r[i].second =
                min(r[i].second, r[i + 1].second + r[i + 1].first - r[i].first);
        long long a = 0;
        for (int i = 0; i < m - 1; ++i)
            a = max(a, (r[i].second + r[i + 1].second + r[i + 1].first -
                        r[i].first) /
                           2);
        return a;
    }
};