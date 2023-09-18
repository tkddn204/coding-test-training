import java.io.*;
import java.util.*;

class Main {

    static boolean[][] map;
    static int dx[] = {1, 0, -1, 0};
    static int dy[] = {0, -1, 0, 1};

    private static void solve(BufferedReader br) throws IOException {
        int n = Integer.parseInt(br.readLine());
        map = new boolean[101][101];

        while (n-- > 0) {
            int[] line = Arrays.stream(br.readLine().split(" "))
                .mapToInt(Integer::parseInt).toArray();
            int x = line[0], y = line[1], d = line[2], g = line[3];

            List<Integer> dir = new ArrayList<>();

            map[x][y] = true;
            x += dx[d];
            y += dy[d];
            map[x][y] = true;
            dir.add(d);

            while (g-- > 0) {
                int size = dir.size();
                for (int i = size - 1; i >= 0; i--) {
                    int nd = (dir.get(i) + 1) % 4;
                    x += dx[nd];
                    y += dy[nd];
                    map[x][y] = true;
                    dir.add(nd);
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                if (map[i][j] && map[i][j + 1] && map[i + 1][j] && map[i + 1][j + 1]) {
                    cnt++;
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
