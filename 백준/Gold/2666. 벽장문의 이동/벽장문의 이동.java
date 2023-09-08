import java.io.*;
import java.util.Arrays;

class Main {

    static int n, l;
    static int a, b;
    static int[] order;
    static int[][][] dp;

    private static int go(int x, int y, int k) {
        if (k == l) return 0;
        if (dp[x][y][k] != 0) return dp[x][y][k];

        int nxt = order[k];

        int left = Math.abs(nxt - x) + go(nxt, y, k + 1);
        int right = Math.abs(nxt - y) + go(x, nxt, k + 1);

        return dp[x][y][k] = Math.min(left, right);
    }

    private static void solve(BufferedReader br) throws IOException {
        n = Integer.parseInt(br.readLine());
        int[] inp = Arrays.stream(br.readLine().split(" "))
            .mapToInt(Integer::parseInt).toArray();
        a = inp[0]; b = inp[1];
        l = Integer.parseInt(br.readLine());

        order = new int[l];
        dp = new int[n + 1][n + 1][l];

        for (int i = 0; i < l; i++) {
            order[i] = Integer.parseInt(br.readLine());
        }

        res.append(go(a, b, 0));
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
