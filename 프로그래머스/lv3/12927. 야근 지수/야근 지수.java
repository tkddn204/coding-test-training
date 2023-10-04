import java.util.*;

class Solution {
    public long solution(int n, int[] works) {
        long answer = 0;
        PriorityQueue<Long> pq = new PriorityQueue<>(Collections.reverseOrder());
        
        for (int work : works) pq.add((long)work);
        
        for (int i = 0; i < n; i++) {
            long work = pq.poll();
            if (work <= 0) break;
            pq.add(work - 1);
        }
        
        return pq.stream().reduce(0L, (sum, work) -> sum + work * work);
    }
}