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

// my solution 
int countOnes(long long x) {
    int cnt = 0;
    while (x > 0) {
        if (x % 2 == 1) cnt++; 
        x = x / 2; 
    }
    return cnt;
}

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (long long k = 1; k <= 60; k++) {
            long long val = (long long)num1 - (long long)num2 * k;

            if (val < k) continue; 

            int ones = countOnes(val); 
            if (ones <= k) {
                return (int)k;
            }
        }
        return -1;
    }
};
