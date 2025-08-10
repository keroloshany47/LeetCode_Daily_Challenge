class Solution {
public:
    
    bool isPowerOfTwo(int x) {
        if (x <= 0) return false;
        while (x % 2 == 0) {
            x /= 2;
        }
        return x == 1;
    }

    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());

        do {
            if (s[0] == '0') continue; 

            int num = stoi(s);
            if (isPowerOfTwo(num)) return true;
        } while (next_permutation(s.begin(), s.end()));

        return false;
    }
};
