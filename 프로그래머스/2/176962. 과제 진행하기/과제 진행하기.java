import java.util.*;

class Solution {
    
    int getTime(String str) {
        String[] time = str.split(":");
        int hour = Integer.parseInt(time[0]);
        int min = Integer.parseInt(time[1]);
        return hour * 60 + min;
    }
    
    class Plan implements Comparable<Plan> {
        String name;
        int start;
        int play;
        
        Plan(String name, int start, int play) {
            this.name = name;
            this.start = start;
            this.play = play;
        }
        
        public int compareTo(Plan p) {
            return Integer.compare(this.start, p.start);
        }
    }
    
    public String[] solution(String[][] plans) {
        int n = plans.length;
        List<String> answer = new ArrayList<>();
        PriorityQueue<Plan> planQue = new PriorityQueue<>();
        
        for (String[] plan : plans) {
            String name = plan[0];
            int start = getTime(plan[1]);
            int play = Integer.parseInt(plan[2]);
            planQue.add(new Plan(name, start, play));
        }
        
        for (Plan plan : planQue) {
            System.out.println(plan.name + " " + plan.start + " " + plan.play);
        }
        
        Stack<Plan> stack = new Stack<>();
        Plan cur = planQue.poll();
        
        int time = cur.start;
        while (time < 60 * 24 + 101) {
            
            // 진행 중이던 과제가 끝난 경우
            if (cur != null && cur.start + cur.play == time) {
                answer.add(cur.name);
                cur = null;
            }
            
            // 새로운 과제를 시작할 시각이 되었을 때
            Plan nxt = planQue.peek();
            if (nxt.start == time) { 
                if (cur != null) { // 진행중인 과제가 있을 때 스택에 넣음
                    cur.play -= time - cur.start;
                    stack.add(cur);
                }
                cur = planQue.poll();
            
            // 멈춰둔 과제가 있을 경우
            } else if (cur == null && !stack.empty()) {
                cur = stack.pop();
                cur.start = time;
            }
            
            // 큐가 비었다 = 현재 일이 마지막 과제일 경우
            if (planQue.isEmpty()) {
                answer.add(cur.name);
                while (!stack.empty()) {
                    answer.add(stack.pop().name);
                }
                break;
            }
            time++;
        }
        
        return answer.toArray(new String[0]);
    }
}