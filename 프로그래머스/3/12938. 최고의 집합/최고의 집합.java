import java.util.*;

class Solution {
    public int[] solution(int n, int s) {
        int k = s / n;
        int r = s % n;
        if (k == 0) return new int[]{-1};
        
        int[] answer = new int[n];
        Arrays.fill(answer, k);
        for (int i = 0; i < r; i++) {
            answer[answer.length - 1 - i]++;
        }
        
        return answer;
    }
}