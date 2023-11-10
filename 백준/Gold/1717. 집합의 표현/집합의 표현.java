import java.io.*;
import java.util.Arrays;

class Main {

    static int n, m;
    static int[] parent;

    static private int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    static private void union(int a, int b) {
        a = find(a);
        b = find(b);

        if (a > b) parent[b] = a;
        else parent[a] = b;
    }

    private static void solve(BufferedReader br) throws IOException {
        int[] split = Arrays.stream(br.readLine().split(" "))
            .mapToInt(Integer::parseInt).toArray();
        n = split[0]; m = split[1];
        parent = new int[n + 1];
        for (int i = 1; i <= n; i++) parent[i] = i;
        while (m-- > 0) {
            int[] line = Arrays.stream(br.readLine().split(" "))
                .mapToInt(Integer::parseInt).toArray();
            int a = line[1], b = line[2];
            if (line[0] == 0) {
                union(a, b);
            } else {
                if (find(a) == find(b)) {
                    res.append("YES").append('\n');
                } else {
                    res.append("NO").append('\n');
                }
            }
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
