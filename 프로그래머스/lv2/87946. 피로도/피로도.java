import java.util.*;

class Solution {
    
    int n;
    int answer;
    boolean[] vst;
    
    void dfs(int k, int x, int[][] dungeons, int cnt) {
        answer = Math.max(answer, cnt);
        
        for (int i = 0; i < n; i++) {
            if (vst[i]) continue;
            if (k < dungeons[i][0]) continue;
            vst[i] = true;
            
            dfs(k - dungeons[i][1], i + 1, dungeons, cnt + 1);
            
            vst[i] = false;
        }
        
    }
    
    public int solution(int k, int[][] dungeons) {
        this.n = dungeons.length;
        this.vst = new boolean[n];
        
        for (int i = 0; i < n; i++) {
            if (k < dungeons[i][0]) continue;
            vst[i] = true;
            dfs(k - dungeons[i][1], i, dungeons, 1);
            vst[i] = false;
        }
        
        return answer;
    }
}