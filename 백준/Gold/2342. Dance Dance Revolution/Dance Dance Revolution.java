import java.io.*;
import java.util.*;

class Main {

    static int[] inp;
    static int[][] power = {
        {1, 2, 2, 2, 2},
        {0, 1, 3, 4, 3},
        {0, 3, 1, 3, 4},
        {0, 4, 3, 1, 3},
        {0, 3, 4, 3, 1}
    };
    static int[][][] dp;

    private static int rec(int k, int l, int r) {
        if (k == inp.length - 1) return 0;
        if (l == r && l != 0) return (int)1e9;
        if (dp[k][l][r] > 0) return dp[k][l][r];

        int nxt = inp[k + 1];
        return dp[k][l][r] = Math.min(
            rec(k + 1, nxt, r) + power[l][nxt],
            rec(k + 1, l, nxt) + power[r][nxt]
        );
    }

    private static void solve(BufferedReader br) throws IOException {
        String line = "0 " + br.readLine();
        inp = Arrays.stream(line.split(" "))
                    .mapToInt(Integer::parseInt).toArray();
        dp = new int[inp.length + 1][5][5];
        res.append(rec(0, 0, 0));

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
