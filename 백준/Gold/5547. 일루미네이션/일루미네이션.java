import java.io.*;
import java.util.*;

class Main {

    static int w, h;
    static int[][] map;
    static boolean[][] vst;

    static int[] owx = {-1, 0, 1, 1, 0, -1}; // 홀수
    static int[] owy = {1, 1, 1, 0, -1, 0};

    static int[] ewx = {-1, 0, 1, 1, 0, -1}; // 짝수
    static int[] ewy = {0, 1, 0, -1, -1, -1};

    static class Pair {
        int x,y;
        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    private static void solve(BufferedReader br) throws IOException {
        int[] inp = Arrays.stream(br.readLine().split(" "))
            .mapToInt(Integer::parseInt).toArray();
        w = inp[0]; h = inp[1];
        map = new int[h + 5][w + 5];
        vst = new boolean[h + 5][w + 5];
        for (int i = 1; i <= h; i++) {
            int[] line = Arrays.stream(br.readLine().split(" "))
                .mapToInt(Integer::parseInt).toArray();
            for (int j = 1; j <= w; j++) {
                map[i][j] = line[j - 1];
            }
        }

        Queue<Pair> que = new LinkedList<>();
        que.add(new Pair(0, 0));
        vst[0][0] = true;
        while (!que.isEmpty()) {
            Pair cur = que.poll();

            for (int d = 0; d < 6; d++) {
                int nx, ny;
                if (cur.x % 2 == 0) {
                    nx = cur.x + ewx[d];
                    ny = cur.y + ewy[d];
                } else {
                    nx = cur.x + owx[d];
                    ny = cur.y + owy[d];
                }

                if (nx < 0 || nx >= h + 2 || ny < 0 || ny >= w + 2) continue;
                if (vst[nx][ny] || map[nx][ny] == 1) continue;
                vst[nx][ny] = true;
                que.add(new Pair(nx, ny));
            }
        }

        int cnt = 0;
        for (int i = 1; i < h + 1; i++) {
            for (int j = 1; j < w + 1; j++) {
                if (map[i][j] == 0) continue;

                for (int d = 0; d < 6; d++) {
                    int nx, ny;
                    if (i % 2 == 0) {
                        nx = i + ewx[d];
                        ny = j + ewy[d];
                    } else {
                        nx = i + owx[d];
                        ny = j + owy[d];
                    }

                    if (nx < 0 || nx >= h + 2 || ny < 0 || ny >= w + 2) continue;
                    if (vst[nx][ny]) cnt++;
                }
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
