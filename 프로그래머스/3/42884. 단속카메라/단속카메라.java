import java.util.*;

class Solution {
    public int solution(int[][] routes) {
        int answer = 0;
        Arrays.sort(routes, (a, b) -> {
            if (a[1] == b[1]) return Integer.compare(a[0], b[0]);
            return Integer.compare(a[1], b[1]);
        });
        
        int pre = -30001;
        for (int[] route: routes) {
            if (pre < route[0]) {
                pre = route[1];
                answer++;
            }
        }
    
        return answer;
    }
}