import java.io.*;
import java.util.*;

class Main {

    static int[] dp;
    private static void solve(BufferedReader br) throws IOException {
        int n = Integer.parseInt(br.readLine());
        int[] inp = Arrays.stream(br.readLine().split(" "))
            .mapToInt(Integer::parseInt).toArray();
        dp = new int[n];
        dp[0] = 1;
        int maxCnt = 1;
        for (int i = 1; i < n; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (inp[j] < inp[i] && dp[i] < dp[j] + 1) {
                    dp[i]++;
                }
            }
            maxCnt = Math.max(maxCnt, dp[i]);
        }
        res.append(maxCnt);
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
