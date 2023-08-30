import java.io.*;
import java.util.*;
import java.util.stream.IntStream;

class Main {

    static int n, m, k;
    static int[] parent;
    static int[] candy;

    private static void solve(BufferedReader br) throws IOException {
        int[] inp = Arrays.stream(br.readLine().split(" "))
            .mapToInt(Integer::parseInt).toArray();
        n = inp[0]; m = inp[1]; k = inp[2];
        candy = Arrays.stream(("0 " + br.readLine()).split(" "))
            .mapToInt(Integer::parseInt).toArray();

        parent = new int[n + 1];
        IntStream.range(1, n + 1).forEach(i -> parent[i] = i);

        while (m-- > 0) {
            int[] line = Arrays.stream(br.readLine().split(" "))
                .mapToInt(Integer::parseInt).toArray();
            uniParent(line[0], line[1]);
        }

        int[] cnt = new int[n + 1];
        Arrays.fill(cnt, 1);
        for (int i = 1; i <= n; i++) {
            if (parent[i] == i) continue;
            int p = getParent(i);
            candy[p] += candy[i];
            cnt[p] += cnt[i];
        }

        int[] dp = new int[3001];
        for (int i = 1; i <= n; i++) {
            if (parent[i] != i) continue;
            for (int j = k - 1; j - cnt[i] >= 0; j--) {
                dp[j] = Math.max(dp[j], dp[j - cnt[i]] + candy[i]);
            }
        }
        res.append(dp[k - 1]);
    }

    static int getParent(int x) {
        if (x == parent[x]) return x;
        return parent[x] = getParent(parent[x]);
    }

    static void uniParent(int a, int b) {
        a = getParent(a);
        b = getParent(b);

        if (a < b) parent[b] = a;
        else parent[a] = b;
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
