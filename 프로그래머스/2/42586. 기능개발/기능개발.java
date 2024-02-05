import java.util.*;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        List<Integer> answer = new ArrayList<>();
        int len = progresses.length;
        
        int end = 0;
        for (int day = 0; day <= 100; day++) {
            for (int i = 0; i < len; i++) progresses[i] += speeds[i];
            int done = 0;
            for (; end < len; end++) {
                if (progresses[end] < 100) break;
                done++;
            }
            if (done > 0) answer.add(done);
        }
        
        return answer.stream().mapToInt(i -> i).toArray();
    }
}