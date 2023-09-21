import java.util.*;

class Solution {
    
    int answer = 0;
    Queue<Integer> que = new LinkedList();
    
    int getNum() {
        long k = 0;
        while(!que.isEmpty()) {
            k += que.poll();
            k *= 10;
        }
        k /= 10;
        return (int)k;
    }
    
    public int solution(String my_string) {
        for (char c : my_string.toCharArray()) {
            if (c >= '0' && c <= '9') que.add(c - '0');
            else {
                if (que.isEmpty()) continue;
                answer += getNum();
            }
        }
        answer += getNum();
        
        return answer;
    }
}