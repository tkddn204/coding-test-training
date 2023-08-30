import java.io.*;
import java.util.*;

class Main {

    static int[][] cost;
    static int[][] dp;

    private static void solve(BufferedReader br) throws IOException {
        int n = Integer.parseInt(br.readLine());
        cost = new int[n + 1][3];

        for (int i = 1; i <= n; i++) {
            cost[i] = Arrays.stream(br.readLine().split(" "))
                .mapToInt(Integer::parseInt).toArray();
        }

        int minVal = (int)1e9;
        for (int f = 0; f < 3; f++) {
            dp = new int[n + 1][3];
            for (int j = 0; j < 3; j++) dp[1][j] = (int)1e9;

            dp[1][f] = cost[1][f];
            for (int i = 2; i <= n; i++) {
                dp[i][0] = Math.min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
                dp[i][1] = Math.min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
                dp[i][2] = Math.min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
            }
            for(int j = 0; j < 3; j++) {
                if (j == f) continue;
                minVal = Math.min(minVal, dp[n][j]);
            }
        }
        res.append(minVal);
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
