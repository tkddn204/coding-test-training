import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

class Main {
    static int n;
    static int[][] w;
    static boolean[] vst;
    static int minCost = Integer.MAX_VALUE;
    static int start;

    private static void backtracking(int a, int cost, int cnt) {
        if (cnt == n) {
            if (w[a][start] != 0)
                minCost = Math.min(minCost, cost + w[a][start]);
            return;
        }

        for (int b = 0; b < n; b++) {
            if (vst[b] || w[a][b] == 0) continue;
            vst[b] = true;
            backtracking(b, cost + w[a][b], cnt + 1);
            vst[b] = false;
        }
    }

    private static void solve(BufferedReader br) throws IOException {
        n = Integer.parseInt(br.readLine());
        w = new int[n][n];
        for (int i = 0; i < n; i++) {
            int[] inp = Arrays.stream(br.readLine().split(" "))
                .mapToInt(Integer::parseInt).toArray();
            for (int j = 0; j < n; j++) {
                w[i][j] = inp[j];
            }
        }

        vst = new boolean[n];
        vst[0] = true;
        start = 0;
        backtracking(0, 0, 1);
        res.append(minCost);
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
