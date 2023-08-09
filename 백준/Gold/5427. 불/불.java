import java.io.*;
import java.util.*;

class Main {
    static int[] dx = {0, 1, 0, -1};
    static int[] dy = {1, 0, -1, 0};
    static int[][] fireVst, sangVst;

    static class Pair {
        int x, y;
        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    private static void solve(BufferedReader br) throws IOException {
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String[] str = br.readLine().split(" ");
            int w = Integer.parseInt(str[0]);
            int h = Integer.parseInt(str[1]);
            fireVst = new int[h][w];
            sangVst = new int[h][w];
            for (int i = 0; i < h; i++) {
                Arrays.fill(fireVst[i], Integer.MAX_VALUE);
                Arrays.fill(sangVst[i], -1);
            }
            Queue<Pair> fireQue = new LinkedList<>();
            Queue<Pair> sangQue = new LinkedList<>();

            String[] building = new String[h];
            for (int i = 0; i < h; i++) {
                building[i] = br.readLine();
                for (int j = 0; j < w; j++) {
                    if (building[i].charAt(j) == '*') {
                        fireQue.add(new Pair(i, j));
                        fireVst[i][j] = 0;
                    } else if (building[i].charAt(j) == '@') {
                        sangQue.add(new Pair(i, j));
                        sangVst[i][j] = 0;
                    }
                }
            }

            // 불이 번지는 시뮬레이션
            while (!fireQue.isEmpty()) {
                Pair cur = fireQue.poll();

                for (int d = 0; d < 4; d++) {
                    int nx = cur.x + dx[d];
                    int ny = cur.y + dy[d];
                    if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                    if (building[nx].charAt(ny) == '#' || building[nx].charAt(ny) == '*') continue;
                    if (fireVst[nx][ny] != Integer.MAX_VALUE) continue;
                    fireQue.add(new Pair(nx, ny));
                    fireVst[nx][ny] = fireVst[cur.x][cur.y] + 1;
                }
            }

            int time = 0;
            boolean escape = false;

            // 상범이가 이동
            while (!sangQue.isEmpty() && !escape) {
                Pair cur = sangQue.poll();

                for (int d = 0; d < 4; d++) {
                    int nx = cur.x + dx[d];
                    int ny = cur.y + dy[d];
                    if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
                        escape = true;
                        time = sangVst[cur.x][cur.y] + 1;
                        break;
                    }
                    if (building[nx].charAt(ny) == '#' || building[nx].charAt(ny) == '*') continue;
                    if (fireVst[nx][ny] <= sangVst[cur.x][cur.y] + 1) continue;
                    if (sangVst[nx][ny] >= 0) continue;
                    sangQue.add(new Pair(nx, ny));
                    sangVst[nx][ny] = sangVst[cur.x][cur.y] + 1;
                }
            }
            
            if (escape) res.append(time).append('\n');
            else res.append("IMPOSSIBLE").append('\n');
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
