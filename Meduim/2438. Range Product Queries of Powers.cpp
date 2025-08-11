class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        
        // Step 1: Extract the powers of 2 from n (binary representation)
        vector<int> exponents;
        int bit = 0;
        while (n > 0) {
            if (n & 1) {  // Check if the least significant bit is 1
                exponents.push_back(bit);
            }
            n >>= 1;  // Right shift to check next bit
            bit++;
        }
        
        // Step 2: Create prefix sum array for quick range sum queries
        vector<long long> prefixSum(exponents.size() + 1, 0);
        for (int i = 0; i < exponents.size(); i++) {
            prefixSum[i + 1] = prefixSum[i] + exponents[i];
        }
        
        // Step 3: Process queries
        vector<int> answers;
        for (auto& query : queries) {
            int left = query[0];
            int right = query[1];
            
            // Sum of exponents in range [left, right]
            long long sumExponents = prefixSum[right + 1] - prefixSum[left];
            
            // Calculate 2^sumExponents mod MOD using fast exponentiation
            long long result = fastPow(2, sumExponents, MOD);
            answers.push_back(result);
        }
        
        return answers;
    }
    
private:
    // Fast exponentiation: calculate (base^exp) % mod
    long long fastPow(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        
        while (exp > 0) {
            if (exp & 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp >>= 1;
        }
        
        return result;
    }
};
