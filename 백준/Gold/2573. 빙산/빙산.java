import java.io.*;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

class Main {

    static int n, m;
    static int[][] map;
    static int[] dx = {0, 1, 0, -1};
    static int[] dy = {1, 0, -1, 0};

    static class Pair {
        int x, y;
        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    private static void solve(BufferedReader br) throws IOException {
        int[] inp = Arrays.stream(br.readLine().split(" "))
            .mapToInt(Integer::parseInt).toArray();
        n = inp[0]; m = inp[1];
        map = new int[n][m];
        for (int i = 0; i < n; i++) {
            int[] line = Arrays.stream(br.readLine().split(" "))
                .mapToInt(Integer::parseInt).toArray();
            map[i] = line;
        }

        int time = 0;
        int cnt = iceCount();
        while (cnt > 0) {
            melt();
            cnt = iceCount();
            time++;
            if (cnt >= 2) {
                res.append(time);
                return;
            }
        }
        res.append(0);
    }

    private static int iceCount() {
        boolean[][] vst = new boolean[n][m];

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vst[i][j] || map[i][j] == 0) continue;
                Queue<Pair> que = new LinkedList<>();
                que.add(new Pair(i, j));

                while (!que.isEmpty()) {
                    Pair cur = que.poll();

                    for (int d = 0; d < 4; d++) {
                        int nx = cur.x + dx[d];
                        int ny = cur.y + dy[d];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (vst[nx][ny] || map[nx][ny] == 0) continue;
                        vst[nx][ny] = true;
                        que.add(new Pair(nx, ny));
                    }
                }
                cnt++;
            }
        }
        return cnt;
    }

    private static void melt() {
        int[][] temp = new int[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 0) continue;

                int cnt = 0;
                for (int d = 0; d < 4; d++) {
                    int nx = i + dx[d];
                    int ny = j + dy[d];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (map[nx][ny] == 0) cnt++;
                }
                temp[i][j] = Math.max(0, map[i][j] - cnt);
            }
        }

        map = temp;
    }

    private static StringBuilder res;
    public static void main(String args[]) throws Exception {
        if (args.length > 1) fileInputOutput(args[0], args[1]);
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            res = new StringBuilder();
            solve(br);
            bw.write(res.toString());
        }
    }

    private static void fileInputOutput(String inputPath, String outputPath) throws IOException {
        System.setIn(new FileInputStream(inputPath));
        System.setOut(
            new PrintStream(
                new BufferedOutputStream(
                    new FileOutputStream(outputPath)
                )));
    }
}
