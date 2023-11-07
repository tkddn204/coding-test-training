import java.io.*;
import java.util.*;

class Main {

    static class Ratio {
        int b, p, q;
        Ratio(int b, int p, int q) {
            this.b = b;
            this.p = p;
            this.q = q;
        }
    }

    static int n;
    static long[] drink;
    static List<ArrayList<Ratio>> graph;
    static boolean[] vst;
    static long lcm = 1;

    static long gcd(long a, long b) {
        if (b == 0) return a;
        else return gcd(b, a % b);
    }

    static void dfs(int cur) {
        vst[cur] = true;
        for (Ratio nxt : graph.get(cur)) {
            if (vst[nxt.b]) continue;
            drink[nxt.b] = drink[cur] * nxt.q / nxt.p;
            dfs(nxt.b);
        }
    }

    private static void solve(BufferedReader br) throws IOException {
        n = Integer.parseInt(br.readLine());
        drink = new long[n];
        graph = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }

        for (int i = 1; i < n; i++) {
            int[] line = Arrays.stream(br.readLine().split(" "))
                .mapToInt(Integer::parseInt).toArray();

            graph.get(line[0]).add(new Ratio(line[1], line[2], line[3]));
            graph.get(line[1]).add(new Ratio(line[0], line[3], line[2]));

            lcm *= line[2] * line[3] / gcd(line[2], line[3]);
        }

        vst = new boolean[n];
        drink[0] = lcm;
        dfs(0);
        lcm = drink[0];
        for (int i = 0; i < n; i++) {
            lcm = gcd(lcm, drink[i]);
        }
        for (int i = 0; i < n; i++) {
            res.append(drink[i] / lcm).append(' ');
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
