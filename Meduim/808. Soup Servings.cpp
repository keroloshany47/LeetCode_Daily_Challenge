class Solution {
public:
    unordered_map<int, unordered_map<int, double>> memo;
    
    double dfs(int a, int b) {
        // Base cases
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0 && b > 0) return 1.0;
        if (a > 0 && b <= 0) return 0.0;
        
        // Memoization check
        if (memo[a][b] != 0) return memo[a][b];
        
        // Recursive calculation
        double res = 0.25 * (
            dfs(a - 100, b) +
            dfs(a - 75, b - 25) +
            dfs(a - 50, b - 50) +
            dfs(a - 25, b - 75)
        );
        
        memo[a][b] = res;
        return res;
    }
    
    double soupServings(int n) {
        // Optimization for large n
        if (n > 5000) return 1.0;
        return dfs(n, n);
    }
};
