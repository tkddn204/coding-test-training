import java.util.*;

class Solution {    
    int n, answer;
    int[] info;
    boolean[][][] vst;
    ArrayList<ArrayList<Integer>> tree;
    
    void dfs(int cur, int sheep, int wolf) {
        if (info[cur] == 0) sheep++;
        else if (info[cur] == 1) wolf++;
        if (sheep == wolf) return;
        
        answer = Math.max(answer, sheep);
        
        int temp = info[cur];
        info[cur] = -1;
        vst[cur][sheep][wolf] = true;

        for (int nxt : tree.get(cur)) {
            if (vst[nxt][sheep][wolf]) continue;
            dfs(nxt, sheep, wolf);
        }
        
        info[cur] = temp;
        vst[cur][sheep][wolf] = false;
    }
    
    public int solution(int[] _info, int[][] edges) {
        n = _info.length;
        info = _info;
        vst = new boolean[n + 1][n + 1][n + 1];
        tree = new ArrayList<>();
        
        for (int i = 0; i <= n; i++) {
            tree.add(new ArrayList<>());
        }
        for (int i = 0; i < edges.length; i++) {
            tree.get(edges[i][0]).add(edges[i][1]);
            tree.get(edges[i][1]).add(edges[i][0]);
        }
        
        dfs(0, 0, 0);
        
        return answer;
    }
}