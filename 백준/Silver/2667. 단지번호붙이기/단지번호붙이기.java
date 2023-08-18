import java.io.*;
import java.util.*;

class Main {

    static int[][] map;
    static boolean[][] vst;
    static int[] dx = {0, 1, 0, -1};
    static int[] dy = {-1, 0, 1, 0};

    static class House {
        int x, y;
        public House(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    private static void solve(BufferedReader br) throws IOException {
        int n = Integer.parseInt(br.readLine());
        map = new int[n][n];
        vst = new boolean[n][n];
        for (int i = 0; i < n; i++) {
            String inp = br.readLine();
            for (int j = 0; j < n; j++) {
                map[i][j] = inp.charAt(j) - '0';
            }
        }

        ArrayList<Integer> cntList = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][j] == 0 || vst[i][j]) continue;
                Queue<House> que = new LinkedList<>();
                que.add(new House(i, j));
                vst[i][j] = true;
                int cnt = 0;
                while (!que.isEmpty()) {
                    House cur = que.poll();
                    cnt++;
                    for (int d = 0; d < 4; d++) {
                        int nx = cur.x + dx[d];
                        int ny = cur.y + dy[d];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if (map[nx][ny] == 0 || vst[nx][ny]) continue;
                        que.add(new House(nx, ny));
                        vst[nx][ny] = true;
                    }
                }
                cntList.add(cnt);
            }
        }
        res.append(cntList.size()).append('\n');
        Collections.sort(cntList);
        for (int cnt: cntList) {
            res.append(cnt).append('\n');
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
