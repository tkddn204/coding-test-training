class Solution {
    
    long perse(int[] sequence, int t) {
        long answer = sequence[0] * t;
        int n = sequence.length;
        for (int i = 0; i < n; i++) {
            sequence[i] *= t;
            t *= -1;
        }
        
        long[] dp = new long[n + 1];
        dp[0] = sequence[0];
        for (int i = 1; i < n; i++) {
            dp[i] = Math.max(dp[i - 1] + sequence[i], sequence[i]);
            answer = Math.max(answer, dp[i]);
        }
        
        return answer;
    }
    
    public long solution(int[] sequence) {
        return Math.max(perse(sequence.clone(), 1), perse(sequence.clone(), -1));
    }
}