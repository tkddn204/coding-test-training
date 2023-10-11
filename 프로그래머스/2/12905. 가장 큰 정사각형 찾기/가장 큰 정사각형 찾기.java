class Solution
{
    
    public int solution(int [][]board)
    {
        int answer = 0;
        
        int[][] newboard = new int[1001][1001];
        int[][] dp = new int[1001][1001];
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                newboard[i + 1][j + 1] = board[i][j];
            }
        }
        
        for (int i = 1; i < 1001; i++) {
            for (int j = 1; j < 1001; j++) {
                if (newboard[i][j] == 0) continue;
                dp[i][j] = 1 + Math.min(dp[i - 1][j - 1], Math.min(dp[i][j - 1], dp[i - 1][j]));
                answer = Math.max(answer, dp[i][j]);
            }
        }
        return answer * answer;
    }
}