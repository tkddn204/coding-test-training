import java.io.*;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

class Main {

    static int n;
    static int m;
    static int[][] box;
    static int[][] vst;
    static int[] dx = {0, 1, 0, -1};
    static int[] dy = {1, 0, -1, 0};

    static class Tomato {
        int x, y;
        public Tomato(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    private static void solve(BufferedReader br) throws IOException {
        int[] inp = Arrays.stream(br.readLine().split(" "))
            .mapToInt(Integer::parseInt).toArray();
        m = inp[0];
        n = inp[1];
        box = new int[n][m];
        vst = new int[n][m];
        Queue<Tomato> que = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            int[] line = Arrays.stream(br.readLine().split(" "))
                .mapToInt(Integer::parseInt).toArray();
            for (int j = 0; j < m; j++) {
                box[i][j] = line[j];
                if (box[i][j] == 1) {
                    que.add(new Tomato(i, j));
                    vst[i][j] = 0;
                } else if (box[i][j] == -1) {
                    vst[i][j] = -1;
                } else {
                    vst[i][j] = -2;
                }
            }
        }

        while (!que.isEmpty()) {
            Tomato cur = que.poll();
            for (int d = 0; d < 4; d++) {
                int nx = cur.x + dx[d];
                int ny = cur.y + dy[d];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (box[nx][ny] != 0 || vst[nx][ny] != -2) continue;
                vst[nx][ny] = vst[cur.x][cur.y] + 1;
                que.add(new Tomato(nx, ny));
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vst[i][j] == -2) {
                    res.append(-1);
                    return;
                }
                cnt = Math.max(cnt, vst[i][j]);
            }
        }
        res.append(cnt);
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
