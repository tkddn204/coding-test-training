import java.util.*;

class Solution {
    public int solution(int[][] data, int col, int row_begin, int row_end) {
        Arrays.sort(data, (a, b) -> {
            if (a[col - 1] == b[col - 1]) {
                return Integer.compare(b[0], a[0]);
            }
            return Integer.compare(a[col - 1], b[col - 1]);
        });
        
        int st = row_begin - 1;
        int answer = 0;
        for (int i = 0; i < data[0].length; i++) {
            answer += data[st][i] % row_begin;
        }
        for (int i = st + 1; i < row_end; i++) {
            int t = 0;
            for (int k = 0; k < data[0].length; k++) {
                t += data[i][k] % (i + 1);
            }
            answer ^= t;
        }
        
        return answer;
    }
}