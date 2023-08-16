import java.io.*;
import java.util.*;

class Main {

    static int[] seq;
    static int[] dp;
    private static void solve(BufferedReader br) throws IOException {
        int n = Integer.parseInt(br.readLine());
        int[] inp = Arrays.stream(br.readLine().split(" "))
            .mapToInt(Integer::parseInt).toArray();
        seq = new int[n];
        dp = new int[n];

        Arrays.fill(seq, -1);
        dp[0] = 1;

        int maxCnt = 1, idx = 0;
        for (int i = 1; i < n; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (inp[j] < inp[i] && dp[i] < dp[j] + 1) {
                    dp[i]++;
                    seq[i] = j;
                    if (maxCnt < dp[i]) {
                        maxCnt = dp[i];
                        idx = i;
                    }
                }
            }
        }

        res.append(maxCnt).append('\n');
        ArrayList<Integer> list = new ArrayList<>();
        while (seq[idx] != -1) {
            list.add(inp[idx]);
            idx = seq[idx];
        }
        list.add(inp[idx]);
        Collections.reverse(list);
        for (int k : list) {
            res.append(k).append(' ');
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
