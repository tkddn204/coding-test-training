import java.util.*;

class Solution {
    
    public int solution(int n, int[][] results) {
        int answer = 0;
        
        int[][] dist = new int[n + 1][n + 1];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) dist[i][j] = 0;
        }
        for (int[] result: results) {
            dist[result[0]][result[1]] = 1;
        }
        
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (dist[i][j] == 0 && dist[i][k] == 1 && dist[k][j] == 1) dist[i][j] = 1;
                }
            }
        }
        
        for (int i = 1; i <= n; i++) {
            int row = 0, col = 0;
            for (int j = 1; j <= n; j++) {
                row += dist[i][j];
                col += dist[j][i];
            }
            if (row + col == n - 1) answer++;
        }
        
        
        return answer;
    }
}