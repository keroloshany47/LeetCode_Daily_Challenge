class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;

        vector<long long> dp(n + 1, 0);     // dp[i] = people who learn on day i
        vector<long long> share(n + 2, 0);  // difference array for sharing

        dp[1] = 1;
        if (1 + delay <= n) share[1 + delay] += 1;
        if (1 + forget <= n) share[1 + forget] -= 1;

        long long cur = 0;
        for (int day = 2; day <= n; day++) {
            cur = (cur + share[day]) % MOD;   // how many people share today
            dp[day] = cur;

            // update future sharing windows
            if (day + delay <= n) {
                share[day + delay] = (share[day + delay] + dp[day]) % MOD;
            }
            if (day + forget <= n) {
                share[day + forget] = (share[day + forget] - dp[day]) % MOD;
                if (share[day + forget] < 0) share[day + forget] += MOD;
            }
        }

        long long ans = 0;
        for (int i = n - forget + 1; i <= n; i++) {
            if (i >= 1) {
                ans = (ans + dp[i]) % MOD;
            }
        }
        return (int)ans;
    }
};
