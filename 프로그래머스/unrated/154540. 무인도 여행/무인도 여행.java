import java.util.*;
class Solution {
    int n, m;
    boolean[][] vst;
    int[] dx = {0, 1, 0, -1};
    int[] dy = {1, 0, -1, 0};
    int sum;

    class Pair {
        int x, y;
        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    
    void dfs(Pair cur, String[] maps) {
        vst[cur.x][cur.y] = true;
        for (int d = 0; d < 4; d++) {
            int nx = cur.x + dx[d];
            int ny = cur.y + dy[d];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (vst[nx][ny] || maps[nx].charAt(ny) == 'X') continue;
            sum += maps[nx].charAt(ny) - '0';
            dfs(new Pair(nx, ny), maps);
        }
    }
    
    public int[] solution(String[] maps) {
        ArrayList<Integer> answerList = new ArrayList<>();
        n = maps.length;
        m = maps[0].length();
        vst = new boolean[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vst[i][j] || maps[i].charAt(j) == 'X') continue;
                
                sum = maps[i].charAt(j) - '0';
                dfs(new Pair(i, j), maps);
                answerList.add(sum);
            }
        }
        if (answerList.isEmpty()) answerList.add(-1);
        else Collections.sort(answerList);
        return answerList.stream().mapToInt(Integer::intValue).toArray();
    }
}