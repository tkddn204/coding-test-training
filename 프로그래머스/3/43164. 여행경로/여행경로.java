import java.util.*;

class Solution {
    
    int n;
    String[][] tickets;
    List<String> answer;
    boolean[] vst;
    
    void dfs(String cur, StringBuilder route, int k) {
        if (k == n) {
            answer.add(route.toString());
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!tickets[i][0].equals(cur)) continue;
            if (vst[i]) continue;
            
            
            route.append(" ").append(tickets[i][1]);
            vst[i] = true;
            
            dfs(tickets[i][1], route, k + 1);
            
            route.delete(route.length() - 4, route.length());
            vst[i] = false;
        }
    }
    
    public String[] solution(String[][] _tickets) {
        tickets = _tickets;
        n = tickets.length;
        
        answer = new ArrayList<>();
        vst = new boolean[n];
        
        dfs("ICN", new StringBuilder("ICN"), 0);
        Collections.sort(answer);
        
        return answer.get(0).split(" ");
    }
}