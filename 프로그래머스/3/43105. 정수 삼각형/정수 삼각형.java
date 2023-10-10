class Solution {
    
    int[][] dp;
    
    public int solution(int[][] triangle) {
        int answer = 0;
        int n = triangle.length;
        dp = new int[n + 1][n + 1];
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (j != 0) dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - 1] + triangle[i][j]);
                if (j != i) dp[i][j] = Math.max(dp[i][j], dp[i - 1][j] + triangle[i][j]);
                answer = Math.max(answer, dp[i][j]);
            }
        }
        
        return answer;
    }
}