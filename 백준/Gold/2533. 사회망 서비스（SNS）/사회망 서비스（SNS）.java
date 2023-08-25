import java.io.*;
import java.util.*;

class Main {

    static int n;
    static boolean[] vst;
    static int[][] dp;
    static ArrayList<Integer>[] tree;

    private static void dfs(int cur) {
        vst[cur] = true;

        dp[cur][0] = 1;
        for (int nxt : tree[cur]) {
            if (vst[nxt]) continue;
            dfs(nxt);
            dp[cur][0] += Math.min(dp[nxt][0], dp[nxt][1]);
            dp[cur][1] += dp[nxt][0];
        }
    }

    private static void solve(BufferedReader br) throws IOException {
        n = Integer.parseInt(br.readLine());
        vst = new boolean[n + 1];
        dp = new int[n + 1][2];
        tree = new ArrayList[n + 1];
        for (int i = 0; i <= n; i++) tree[i] = new ArrayList<>();
        for (int i = 0; i < n - 1; i++) {
            int[] inp = Arrays.stream(br.readLine().split(" "))
                .mapToInt(Integer::parseInt).toArray();
            int u = inp[0], v = inp[1];
            tree[u].add(v);
            tree[v].add(u);
        }

        dfs(1);

        res.append(Math.min(dp[1][0], dp[1][1]));
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
