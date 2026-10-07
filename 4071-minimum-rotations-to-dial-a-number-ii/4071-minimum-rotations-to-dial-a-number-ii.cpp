class Solution {
public:
    int minRotations(int n, string s) {
        int ans = 0;
        int mini = INT_MAX;

        for(int i = 0; i < n; i++)
        {
            int prev = (i == 0 ? 0 : s[i-1] - '0');
            int curr = s[i] - '0';

            int diff = abs(curr - prev);
            ans += min(diff, 10 - diff);
        }

        mini = ans;

        for(int i = 0; i < n - 1; i++)
        {
            if(i == 0)
            {
                int sub = min(s[0] - '0', 10 - (s[0] - '0'));
                int add = min(s[n-1] - '0', 10 - (s[n-1] - '0'));

                int val = ans - sub + add;
                mini = min(mini, val);
            }
            else
            {
                int prev = s[i-1] - '0';
                int curr = s[i] - '0';
                int last = s[n-1] - '0';

                int diff1 = abs(curr - prev);
                int remove = min(diff1, 10 - diff1);

                int diff2 = abs(last - prev);
                int add = min(diff2, 10 - diff2);

                int val = ans - remove + add;

                mini = min(mini, val);
            }
        }

        return mini;
    }
};