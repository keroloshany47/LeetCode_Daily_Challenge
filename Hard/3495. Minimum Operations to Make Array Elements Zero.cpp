class Solution {
public:
    long long calcPrefix(long long n) {
        if (n <= 0) return 0;
        long long sum = 0;
        long long base = 1;
        int step = 1;
        while (base <= n) {
            long long next = base * 4 - 1; 
            long long right = min(n, next);
            long long count = right - base + 1;
            sum += count * step;
            base *= 4;
            step++;
        }
        return sum;
    }

    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        for (auto &q : queries) {
            long long l = q[0], r = q[1];
            long long totalSteps = calcPrefix(r) - calcPrefix(l - 1);
            ans += (totalSteps + 1) / 2;
        }
        return ans;
    }
};
