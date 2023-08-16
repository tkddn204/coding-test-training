import java.io.*;
import java.lang.reflect.Array;
import java.util.Arrays;

class Main {

    static int n;
    static double[] pr = new double[4];
    static boolean[][] vst = new boolean[31][31];
    static int[] dx = {0, 0, -1, 1};
    static int[] dy = {1, -1, 0, 0};
    static double total;

    private static void dfs(int x, int y, double per, int cnt) {
        if (cnt == n) {
            total += per;
            return;
        }

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (vst[nx][ny]) continue;
            vst[nx][ny] = true;
            dfs(nx, ny, per * pr[d], cnt + 1);
            vst[nx][ny] = false;
        }
    }

    private static void solve(BufferedReader br) throws IOException {
        int[] inp = Arrays.stream(br.readLine().split(" "))
            .mapToInt(Integer::parseInt).toArray();
        n = inp[0];
        for (int i = 0; i < 4; i++) {
            pr[i] = (double)inp[i + 1] / 100;
        }

        vst[14][14] = true;
        dfs(14, 14, 1, 0);

        res.append(total);
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
