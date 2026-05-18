class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1)
            return 0;

        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        vector<bool> vis(n, false);
        queue<int> q;

        q.push(0);
        vis[0] = true;

        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                int i = q.front();
                q.pop();

                if (i == n - 1)
                    return steps;

                vector<int> next = mp[arr[i]];
                next.push_back(i - 1);
                next.push_back(i + 1);

                for (int j : next) {
                    if (j >= 0 && j < n && !vis[j]) {
                        vis[j] = true;
                        q.push(j);
                    }
                }

                mp[arr[i]].clear();
            }

            steps++;
        }

        return -1;
    }
};