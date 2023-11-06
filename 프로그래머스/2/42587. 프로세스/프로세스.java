import java.util.*;

class Solution {
    
    class Process {
        int p, idx;
        Process(int p, int idx) {
            this.p = p;
            this.idx = idx;
        }
    }
    
    public int solution(int[] priorities, int location) {
        int answer = 0;
        
        Queue<Process> que = new LinkedList<>();
        
        for (int i = 0; i < priorities.length; i++) {
            que.add(new Process(priorities[i], i));
        }
        
        int cnt = 0;
        while (!que.isEmpty()) {
            Process cur = que.poll();
            boolean more = false;
            if (!que.isEmpty()) {
                for (Process other : que) {
                    if (other.p > cur.p) {
                        more = true;
                        break;
                    }
                }
            }
            
            if (more) {
                que.add(cur);
            } else {
                cnt++;
                if (cur.idx == location) {
                    break;
                }
            }
        }
        
        return cnt;
    }
}