import java.util.*;

class Solution {
    
    boolean diff(String a, String b) {
        int cnt = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a.charAt(i) != b.charAt(i)) cnt++;
            if (cnt > 1) return false;
        }
        return true;
    }
    
    public int solution(String begin, String target, String[] words) {
        if (!Arrays.asList(words).contains(target)) {
            return 0;
        }
        
        Map<String, Integer> vst = new HashMap<>();
        Queue<String> que = new LinkedList<>();
        que.add(begin);
        vst.put(begin, 0);
        while (!que.isEmpty()) {
            String cur = que.poll();
            if (cur == target) break;
            for (String nxt : words) {
                if (vst.containsKey(nxt)) continue;
                if (!diff(cur, nxt)) continue;
                que.add(nxt);
                vst.put(nxt, vst.get(cur) + 1);
            }
        }
        
        return vst.get(target);
    }
}