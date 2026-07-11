class Solution {
public:
    vector<int> pathExistenceQueries(
        int n,
        vector<int>& nums,
        int maxDiff,
        vector<vector<int>>& queries
    ) {
        vector<pair<int, int>> a;
        for (int i = 0; i < n; i++) {
            a.push_back({nums[i], i});
        }

        sort(a.begin(), a.end());

        vector<int> pos(n);
        for (int i = 0; i < n; i++) {
            pos[a[i].second] = i;
        }

        vector<int> nxt(n);
        int j = 0;

        for (int i = 0; i < n; i++) {
            j = max(j, i);

            while (j + 1 < n &&
                   a[j + 1].first - a[i].first <= maxDiff) {
                j++;
            }

            nxt[i] = j;
        }

        int LOG = 0;
        while ((1 << LOG) <= n) {
            LOG++;
        }

        vector<vector<int>> up(LOG + 1, vector<int>(n));

        for (int i = 0; i < n; i++) {
            up[0][i] = nxt[i];
        }

        for (int k = 1; k <= LOG; k++) {
            for (int i = 0; i < n; i++) {
                up[k][i] = up[k - 1][up[k - 1][i]];
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int l = pos[q[0]];
            int r = pos[q[1]];

            if (l > r) {
                swap(l, r);
            }

            if (l == r) {
                ans.push_back(0);
                continue;
            }

            if (up[LOG][l] < r) {
                ans.push_back(-1);
                continue;
            }

            int cur = l;
            int edges = 0;

            for (int k = LOG; k >= 0; k--) {
                if (up[k][cur] < r) {
                    cur = up[k][cur];
                    edges += (1 << k);
                }
            }

            ans.push_back(edges + 1);
        }

        return ans;
    }
};