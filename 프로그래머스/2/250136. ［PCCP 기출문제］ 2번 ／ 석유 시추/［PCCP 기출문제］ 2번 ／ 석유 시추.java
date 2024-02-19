import java.util.*;

class Solution {
    class Pair {
        int x, y;
        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    int[] dx = new int[]{1, 0, -1, 0};
    int[] dy = new int[]{0, 1, 0, -1};
    public int solution(int[][] land) {
        int n = land.length;
        int m = land[0].length;
        int answer = 0;
        Map<Integer, Integer> map = new HashMap<>();
        int[][] vst = new int[n][m];
        int k = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vst[i][j] > 0 || land[i][j] == 0) continue;
                
                Queue<Pair> que = new LinkedList<>();
                que.add(new Pair(i, j));
                vst[i][j] = k;
                map.put(k, 1);
                while (!que.isEmpty()) {
                    Pair cur = que.poll();
                    
                    for (int d = 0; d < 4; d++) {
                        int nx = cur.x + dx[d];
                        int ny = cur.y + dy[d];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (vst[nx][ny] > 0 || land[nx][ny] == 0) continue;
                        que.add(new Pair(nx, ny));
                        map.put(k, map.getOrDefault(k, 0) + 1);
                        vst[nx][ny] = k;
                    }
                }
                k++;
            }
        }
        
        for (int j = 0; j < m; j++) {
            Set<Integer> set = new HashSet<>();
            for (int i = 0; i < n; i++) {
                set.add(vst[i][j]);
            }
            int cnt = 0;
            for (int s: set) {
                cnt += map.getOrDefault(s, 0);
            }
            answer = Math.max(answer, cnt);
        }
        
        return answer;
    }
}