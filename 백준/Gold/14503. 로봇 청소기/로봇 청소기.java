import java.io.*;
import java.util.*;

class Main {

    static int n, m;
    static int r, c, dir;
    static int[][] room;
    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, 1, 0, -1};

    private static void solve(BufferedReader br) throws IOException {
        int[] inp = Arrays.stream(br.readLine().split(" "))
            .mapToInt(Integer::parseInt).toArray();
        n = inp[0]; m = inp[1];
        int[] robot = Arrays.stream(br.readLine().split(" "))
            .mapToInt(Integer::parseInt).toArray();
        r = robot[0]; c = robot[1]; dir = robot[2];
        room = new int[n][m];
        for (int i = 0; i < n; i++) {
            int[] line = Arrays.stream(br.readLine().split(" "))
                .mapToInt(Integer::parseInt).toArray();
            room[i] = line;
        }

        int cnt = 0;
        while (true) {
            if (room[r][c] == 0) {
                room[r][c] = -1;
                cnt++;
            }

            boolean isClean = true;
            for (int d = 0; d < 4; d++) {
                int nx = r + dx[d];
                int ny = c + dy[d];
                if (room[nx][ny] == 0) {
                    isClean = false;
                    break;
                }
            }

            if (isClean) {
                int nxtdir = (dir + 2) % 4;
                int nx = r + dx[nxtdir];
                int ny = c + dy[nxtdir];
                if (room[nx][ny] == 1) break;
                r = nx; c = ny;
            } else {
                dir--;
                if (dir < 0) dir = 3;
                int nx = r + dx[dir];
                int ny = c + dy[dir];
                if (room[nx][ny] == 0) {
                    r = nx; c = ny;
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
