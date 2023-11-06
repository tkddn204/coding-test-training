import java.util.*;

class Solution {
    
    class Pair {
        int x, y;
        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    
    int n, m;
    int[] dx = new int[]{0, 1, 0, -1};
    int[] dy = new int[]{1, 0, -1, 0};
    
    public int solution(String[] maps) {
        n = maps.length;
        m = maps[0].length();
        
        Pair st = null;
        Pair lv = null;
        Pair en = null;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (maps[i].charAt(j) == 'S') {
                    st = new Pair(i, j);
                } else if (maps[i].charAt(j) == 'L') {
                    lv = new Pair(i, j);
                } else if (maps[i].charAt(j) == 'E') {
                    en = new Pair(i, j);
                } 
            }
        }
        
        int a = bfs(maps, st, lv);
        if (a == -1) return -1;
        int b = bfs(maps, lv, en);
        if (b == -1) return -1;
        return a + b;
    }
    
    int bfs(String[] maps, Pair st, Pair en) {
        int[][] vst = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vst[i][j] = -1;
            }
        }
        
        Queue<Pair> que = new LinkedList<>();
        que.add(st);
        vst[st.x][st.y] = 0;
        while (!que.isEmpty()) {
            Pair cur = que.poll();
            
            if (cur.x == en.x && cur.y == en.y) break;
            
            for (int d = 0; d < 4; d++) {
                int nx = cur.x + dx[d];
                int ny = cur.y + dy[d];
                
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (maps[nx].charAt(ny) == 'X' || vst[nx][ny] > -1) continue;
                que.add(new Pair(nx, ny));
                vst[nx][ny] = vst[cur.x][cur.y] + 1;
            }
        }
        
        return vst[en.x][en.y];
    }
}