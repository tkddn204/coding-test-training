import java.util.*;

class Solution {
    public int solution(int[] elements) {
        int n = elements.length;
        int[][] sum = new int[n + 1][n + 1];
        
        // 누적합
        for (int i = 0; i < n; i++) {
            sum[i][i] = elements[i];
            for (int j = i + 1; j < n; j++) {
                sum[i][j] = sum[i][j - 1] + elements[j];
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                sum[i][j] = sum[i][n - 1] + sum[0][j];
            }
        }
        
        Set<Integer> s = new HashSet();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                s.add(sum[i][j]);
            }
        }
        
        return s.size();
    }
}