import java.util.*;

class Solution {
    
    public int solution(String name) {
        int answer = 0;
        int cur = 0;
        int mv = name.length() - 1;
        for (int i = 0; i < name.length(); i++) {
            answer += Math.min(name.charAt(i) - 'A', 'Z' - name.charAt(i) + 1);
            cur = i + 1;
            while (cur <  name.length() && name.charAt(cur) == 'A') cur++;
            mv = Math.min(mv, i * 2 + name.length() - cur);
            mv = Math.min(mv, (name.length() - cur) * 2 + i);
        }
        
        return answer + mv;
    }
}