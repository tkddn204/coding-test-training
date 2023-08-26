import java.io.*;
import java.util.*;

class Main {

    private static char[][] map;
    private static int[] num;
    private static int[] dx = {0, 1, 0, -1};
    private static int[] dy = {1, 0, -1, 0};
    private static int cnt;

    static class Pair {
        int x, y;
        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    private static boolean check() {
        boolean[][] temp = new boolean[5][5]; // 경우의 수에 따른 번호 체크용 배열
        boolean[][] vst = new boolean[5][5]; // BFS 방문배열

        Queue<Pair> que = new LinkedList<>();

        // 번호에 따라 체크 배열 만들기
        for (int i = 0; i < 7; i++) {
            int x = num[i] / 5;
            int y = num[i] % 5;
            temp[x][y] = true;
            if (que.isEmpty()) {
                que.add(new Pair(x, y));
                vst[x][y] = true;
            }
        }

        // 한 줄로 이어져 있는지 확인
        int som = 0, yeon = 0;
        while (!que.isEmpty()) {
            Pair cur = que.poll();

            if (map[cur.x][cur.y] == 'Y') yeon++;
            else som++;

            for (int d = 0; d < 4; d++) {
                int nx = cur.x + dx[d];
                int ny = cur.y + dy[d];

                if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
                if (!temp[nx][ny] || vst[nx][ny]) continue;

                que.add(new Pair(nx, ny));
                vst[nx][ny] = true;
            }
        }

        return som >= 4 && som + yeon == 7;
    }

    private static void bt(int k, int depth) {
        if (depth == 7) {
            if (check()) cnt++;
            return;
        }

        for (int i = k; i < 25; i++) {
            num[depth] = i;
            bt(i + 1, depth + 1);
        }
    }

    private static void solve(BufferedReader br) throws IOException {
        map = new char[5][5];
        num = new int[7];
        for (int i = 0; i < 5; i++) {
            String line = br.readLine();
            for (int j = 0; j < 5; j++) {
                map[i][j] = line.charAt(j);
            }
        }

        bt(0, 0);
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
