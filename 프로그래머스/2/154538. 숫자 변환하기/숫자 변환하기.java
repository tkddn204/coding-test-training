import java.util.*;

class Solution {
    public int solution(int x, int y, int n) {
        int answer = 0;
        
        Queue<Integer> que = new LinkedList<>();
        int[] vst = new int[1000001];
        Arrays.fill(vst, -1);
        
        que.add(x);
        vst[x] = 0;
        
        while (!que.isEmpty()) {
            int cur = que.poll();
            if (cur == y) break;
            
            for (int nxt: new int[]{cur + n, cur * 2, cur * 3}) {
                if (nxt > 1000000) continue;
                if (vst[nxt] > -1) continue;
                que.add(nxt);
                vst[nxt] = vst[cur] + 1;
            }
        }
        
        return vst[y];
    }
}