import java.util.*;

class Solution {
    
    class Pair {
        int x, y;
        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    
    int[][] map;
    int[] dx = new int[]{0, 1, 0, -1, 1, 1, -1, -1};
    int[] dy = new int[]{1, 0, -1, 0, -1, 1, 1, -1};
    
    public int solution(int[][] rectangle, int characterX, int characterY, int itemX, int itemY) {
        map = new int[101][101];
        characterX *= 2;
        characterY *= 2;
        itemX *= 2;
        itemY *= 2;
        
        for (int i = 0; i < rectangle.length; i++) {
            int stx = 2*rectangle[i][0]; int sty = 2*rectangle[i][1];
            int enx = 2*rectangle[i][2]; int eny = 2*rectangle[i][3];
            
            for (int j = stx; j <= enx; j++) {
                for (int k = sty; k <= eny; k++) {
                    if (map[j][k] == 1) continue;
                    map[j][k] = 1;
                    if (j == stx || j == enx || k == sty || k == eny) {
                        map[j][k] = 2;
                    }
                }
            }
        }
        
        int[][] dist = new int[101][101];
        for (int i = 0; i < 101; i++) {
            for (int j = 0; j < 101; j++) {
                dist[i][j] = -1;
            }
        }
        
        Queue<Pair> que = new LinkedList<>();
        que.add(new Pair(characterX, characterY));
        dist[characterX][characterY] = 0;
        
        while (!que.isEmpty()) {
            Pair cur = que.poll();
            
            for (int d = 0; d < 4; d++) {
                int nx = cur.x + dx[d];
                int ny = cur.y + dy[d];
                if (nx < 0 || nx >= 101 || ny < 0 || ny >= 101) continue;
                if (map[nx][ny] != 2 || dist[nx][ny] >= 0) continue;
                dist[nx][ny] = dist[cur.x][cur.y] + 1;
                que.add(new Pair(nx, ny));
            }
        }
        
        // for (int i = 0; i < 25; i++) {
        //     for (int j = 0; j < 25; j++) {
        //         if (dist[i][j] == -1) System.out.print("-  ");
        //         else System.out.print(dist[i][j] + " ");
        //     }
        //     System.out.println();
        // }
        
        
        return dist[itemX][itemY] / 2;
    }
}