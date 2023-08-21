import java.io.*;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

class Main {

    static int n;
    static int m;
    static int[][] miro;
    static boolean[][][][] vst;
    static int[] dx = {0, 1, 0, -1};
    static int[] dy = {1, 0, -1, 0};

    static class State {
        int x, y;
        int mv;
        public State(int x, int y, int mv) {
            this.x = x;
            this.y = y;
            this.mv = mv;
        }
    }

    private static void solve(BufferedReader br) throws IOException {
        int[] inp = Arrays.stream(br.readLine().split(" "))
            .mapToInt(Integer::parseInt).toArray();
        n = inp[0];
        m = inp[1];
        miro = new int[n][n];
        vst = new boolean[11][2][n][n];
        for (int i = 0; i < n; i++) {
            int[] line = Arrays.stream(br.readLine().split(" "))
                .mapToInt(Integer::parseInt).toArray();
            for (int j = 0; j < n; j++) {
                miro[i][j] = line[j];
            }
        }

        Queue<State> que = new LinkedList<>();
        que.add(new State(0, 0, 0));
        vst[0][0][0][0] = true;

        int minMv = Integer.MAX_VALUE;
        while(!que.isEmpty()) {
            State cur = que.poll();

            if (cur.x == n - 1 && cur.y == n - 1) {
                minMv = cur.mv;
                break;
            }

            for (int d = 0; d < 4; d++) {
                int nx = cur.x + dx[d];
                int ny = cur.y + dy[d];
                int nmv = (cur.mv + 1) % m;

                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                int curDay = (cur.mv / m) % 2;
                int nxtDay = ((cur.mv + 1) / m) % 2;
                if (vst[nmv][nxtDay][nx][ny]) continue;
                if (miro[nx][ny] == 1) {
                    if (curDay == 0) continue;
                    boolean canGo = true;
                    while (miro[nx][ny] == 1) {
                        nx += dx[d];
                        ny += dy[d];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
                            canGo = false;
                            break;
                        }
                        if (vst[nmv][nxtDay][nx][ny]) {
                            canGo = false;
                            break;
                        }
                    }
                    if (!canGo) continue;
                }
                que.add(new State(nx, ny, cur.mv + 1));
                vst[nmv][nxtDay][nx][ny] = true;
            }
        }

        if (minMv == Integer.MAX_VALUE) res.append(-1);
        else {
            res.append(minMv / (2*m) + 1).append(' ');
            String resDay = (minMv / m) % 2 == 0 ? "sun" : "moon";
            res.append(resDay);
        }
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
