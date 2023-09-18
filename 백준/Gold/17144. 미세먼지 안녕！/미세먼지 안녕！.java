import java.io.*;
import java.util.*;

class Main {

    static int r, c, t;
    static int[][] map;
    static int[] air;
    static int[] dx = {0, -1, 0, 1};
    static int[] dy = {1, 0, -1, 0};

    private static void solve(BufferedReader br) throws IOException {
        int[] line = Arrays.stream(br.readLine().split(" "))
            .mapToInt(Integer::parseInt).toArray();
        r = line[0]; c = line[1]; t = line[2];

        map = new int[r][c];
        air = new int[2];

        int airIdx = 0;
        for (int i = 0; i < r; i++) {
            map[i] = Arrays.stream(br.readLine().split(" "))
                .mapToInt(Integer::parseInt).toArray();
            if (map[i][0] == -1) {
                air[airIdx++] = i;
            }
        }

        while (t-- > 0) {
            spread();
            wind();
//            printmap();
        }

        int sum = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (map[i][j] == -1) continue;
                sum += map[i][j];
            }
        }
        res.append(sum);
    }

    private static void printmap() {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                res.append(map[i][j]).append(' ');
            }
            res.append('\n');
        }
    }


    private static void spread() {
        int[][] temp = new int[r][c];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (map[i][j] <= 0) continue;

                int cnt = 0;
                for (int d = 0; d < 4; d++) {
                    int nx = i + dx[d];
                    int ny = j + dy[d];

                    if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                    if (map[nx][ny] == -1) continue;
                    temp[nx][ny] += map[i][j] / 5;
                    cnt++;
                }
                temp[i][j] += map[i][j] - (map[i][j] / 5) * cnt;
            }
        }
        temp[air[0]][0] = -1;
        temp[air[1]][0] = -1;
        map = temp;
    }

    private static void wind() {
        // 위쪽
        for (int i = 0; i < 2; i++) {
            int nx = air[i];
            int ny = 1;
            int d = 0;
            int nxt = map[nx][ny];
            map[nx][ny] = 0;
            while (true) {
                int cur = nxt;

                nx += dx[d];
                ny += dy[d];
                if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
                    nx -= dx[d];
                    ny -= dy[d];
                    if (i == 0) d = (d + 1) % 4; // 위쪽(시계)
                    else d = d > 0 ? d - 1: 3; // 아래쪽(반시계)
                    continue;
                }
                if (map[nx][ny] == -1) break;

                nxt = map[nx][ny];
                map[nx][ny] = cur;
            }
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
