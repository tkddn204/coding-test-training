class Solution {
    public int solution(String arr[]) {
        int n = (arr.length / 2) + (arr.length % 2);
        int[][] mindp = new int[n][n];
        int[][] maxdp = new int[n][n];
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    mindp[i][j] = Integer.parseInt(arr[2 * i]);
                    maxdp[i][j] = Integer.parseInt(arr[2 * i]);
                } else {
                    mindp[i][j] = Integer.MAX_VALUE;
                    maxdp[i][j] = Integer.MIN_VALUE;
                }
            }
        }
        
        for (int len = 1; len < n; len++) {
            for (int st = 0; st < n - len; st++) {
                int en = st + len;
                for (int k = st; k < en; k++) {
                    if (arr[k * 2 + 1].equals("+")) {
                        mindp[st][en] = Math.min(mindp[st][en], mindp[st][k] + mindp[k + 1][en]);
                        maxdp[st][en] = Math.max(maxdp[st][en], maxdp[st][k] + maxdp[k + 1][en]);
                    } else {
                        mindp[st][en] = Math.min(mindp[st][en], mindp[st][k] - maxdp[k + 1][en]);
                        maxdp[st][en] = Math.max(maxdp[st][en], maxdp[st][k] - mindp[k + 1][en]);
                    }
                }
            }
        }
        
        return maxdp[0][n - 1];
    }
}