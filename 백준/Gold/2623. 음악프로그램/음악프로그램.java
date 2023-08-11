import java.io.*;
import java.util.*;

class Main {

    static int n;
    static ArrayList<Integer>[] graph;
    static int[] deg;

    private static void solve(BufferedReader br) throws IOException {
        int[] inp = Arrays.stream(br.readLine().split(" "))
            .mapToInt(Integer::parseInt).toArray();
        n = inp[0];
        int m = inp[1];

        graph = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) graph[i] = new ArrayList<>();
        deg = new int[n + 1];

        while (m-- > 0) {
            int[] line = Arrays.stream(br.readLine().split(" "))
                .mapToInt(Integer::parseInt).toArray();
            int k = line[0];
            int f = line[1];
            for (int i = 2; i <= k; i++) {
                graph[f].add(line[i]);
                deg[line[i]]++;
                f = line[i];
            }
        }

        ArrayList<Integer> order = new ArrayList<>();
        Queue<Integer> que = new LinkedList<>();
        for (int i = 1; i <= n; i++) {
            if (deg[i] == 0) que.add(i);
        }
        while (!que.isEmpty()) {
            int cur = que.poll();
            order.add(cur);
            for (int nxt : graph[cur]) {
                deg[nxt]--;
                if (deg[nxt] == 0) que.add(nxt);
            }
        }
        if (order.size() == n) {
            for (int e: order) res.append(e).append('\n');
        } else {
            res.append(0);
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
