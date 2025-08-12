class Solution:
    MOD = 10**9 + 7
    
    def numberOfWays(self, n: int, x: int) -> int:
        # Precompute all powers i^x <= n
        powers = []
        base = 1
        while True:
            p = base ** x
            if p > n:
                break
            powers.append(p)
            base += 1
        
        # dp[j] = number of ways to sum to j using unique powers
        dp = [0] * (n + 1)
        dp[0] = 1
        
        # For each power, update dp in reverse to avoid reuse
        for p in powers:
            for j in range(n, p - 1, -1):
                dp[j] = (dp[j] + dp[j - p]) % self.MOD
        
        return dp[n]
