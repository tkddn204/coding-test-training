import java.util.*;

class Solution {
    public int[] solution(String[] operations) {
        int[] answer = {};
        
        PriorityQueue<Integer> minpq = new PriorityQueue<>();
        PriorityQueue<Integer> maxpq = new PriorityQueue<>(Collections.reverseOrder());
        
        for (String oper : operations) {
            String[] splited = oper.split(" ");
            if (splited[0].equals("I")) {
                int val = Integer.parseInt(splited[1]);
                minpq.add(val);
                maxpq.add(val);
            } else {
                if (maxpq.isEmpty()) continue;
                if (splited[1].equals("1")) {
                    int val = maxpq.poll();
                    minpq.remove(val);
                } else {
                    int val = minpq.poll();
                    maxpq.remove(val);
                }
            }
        }
        
        if (maxpq.isEmpty()) answer = new int[]{0, 0};
        else answer = new int[]{maxpq.peek(), minpq.peek()};
        
        return answer;
    }
}