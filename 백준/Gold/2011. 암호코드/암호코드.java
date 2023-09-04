import java.io.*;

class Main {

    static final int MOD = 1000000;
    static long[] dp;

    private static void solve(BufferedReader br) throws IOException {
        String str = br.readLine();
        int size = str.length();
        str = "0" + str;

        dp = new long[5001];
        dp[0] = 1;
        for (int i = 1; i <= size; i++) {
            if (str.charAt(i) > '0') {
                dp[i] = (dp[i] + dp[i - 1]) % MOD;
            }

            if (str.charAt(i - 1) == '1') {
                dp[i] = (dp[i] + dp[i - 2]) % MOD;
            } else if (str.charAt(i - 1) == '2' && str.charAt(i) <= '6') {
                dp[i] = (dp[i] + dp[i - 2]) % MOD;
            }
        }

        res.append(dp[size]);
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
