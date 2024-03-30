class Solution {
    
    int MOD = 1000000007;
    
    public int solution(int n) {
        long dp[] = new long[100001];
        dp[0] = dp[1] = 1;
        dp[2] = 3;
        dp[3] = 10;
        dp[4] = 23;
        dp[5] = 62;
        
        for (int i = 6; i <= n; i++) {
            dp[i] = (dp[i - 1]
                     + dp[i - 2] * 2
                     + dp[i - 3] * 6
                     + dp[i - 4]
                     - dp[i - 6]
                     + MOD) % MOD;
        }
        
        return (int) dp[n];
    }
}