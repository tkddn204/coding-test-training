import java.util.*;

class Solution {
    
    ArrayList<ArrayList<Integer>> graph;
    boolean[] light;
    boolean[] vst;
    int answer;
    
    public void dfs(int cur, int n) {
        vst[cur] = true;
        
        boolean isOn = false;
        for (int nxt : graph.get(cur)) {
            if (vst[nxt]) continue;
            dfs(nxt, n);
            if (!light[nxt]) {
                isOn = true;
            }
        }
        if (isOn) {
            light[cur] = true;
            answer++;
        }
    }
    
    public int solution(int n, int[][] lighthouse) {
        graph = new ArrayList<>(n + 1);
        light = new boolean[n + 1];
        vst = new boolean[n + 1];
        
        for (int i = 0; i < n + 1; i++) {
            graph.add(new ArrayList<>());
        }
        
        for (int[] point : lighthouse) {
            graph.get(point[0]).add(point[1]);
            graph.get(point[1]).add(point[0]);
        }
        
        dfs(1, n);
        
        return answer;
    }
}