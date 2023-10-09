import java.util.*;

class Solution {
    public int solution(int storey) {
        int answer = 0;
        
        while (storey > 0) {
            int d = storey % 10;
            int cnt = d > 5 ? 10 - d : d;
            answer += cnt;
            if (d == 5 && storey > 10 && ((storey / 10) % 10) >= 5) {
                storey += cnt;
            } else {
                storey += d > 5 ? cnt : -cnt;
            }
            storey /= 10;
        }
        
        return answer;
    }
}