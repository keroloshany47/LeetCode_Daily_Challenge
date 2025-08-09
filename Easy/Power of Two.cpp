class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false; // Powers of 2 are positive only
        
        while (n % 2 == 0) { // Keep dividing by 2 if even
            n /= 2;
        }
        
        return n == 1; // If we end with 1, it's a power of two
    }
};
