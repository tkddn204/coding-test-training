import java.util.*;

class Solution {
    class Pair {
        int x, y;
        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    
    int[] dx = {0, 1, 0, -1};
    int[] dy = {1, 0, -1, 0};
    
    public int solution(int[][] maps) {
        int n = maps.length;
        int m = maps[0].length;
        int[][] vst = new int[n][m];
        for (int i = 0; i < n; i++)
            Arrays.fill(vst[i], -1);
        
        Queue<Pair> que = new LinkedList<>();
        que.add(new Pair(0, 0));
        vst[0][0] = 1;
        while (!que.isEmpty()) {
            Pair cur = que.poll();
            
            for (int d = 0; d < 4; d++) {
                int nx = cur.x + dx[d];
                int ny = cur.y + dy[d];
                
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (vst[nx][ny] > -1 || maps[nx][ny] == 0) continue;
                que.add(new Pair(nx, ny));
                vst[nx][ny] = vst[cur.x][cur.y] + 1;
            }
        }
        
        return vst[n - 1][m - 1];
    }
}