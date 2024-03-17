import java.util.*;

class Solution {
    public int solution(int[] A, int[] B) {
        int answer = 0;
        
        Arrays.sort(A);
        Arrays.sort(B);
        
        int b = 0;
        for (int a = 0; a < A.length; a++) {
            while (b < B.length && A[a] >= B[b]) b++;
            if (b == B.length) break;
            answer++;
            b++;
        }
        
        return answer;
    }
}