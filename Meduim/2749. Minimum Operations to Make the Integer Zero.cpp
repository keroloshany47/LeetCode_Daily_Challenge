class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (long long k = 1; k <= 60; k++) {
            long long val = (long long)num1 - (long long)num2 * k;
            if (val < k) continue; 
            if (__builtin_popcountll(val) <= k) {
                return (int)k;
            }
        }
        return -1;
    }
};
