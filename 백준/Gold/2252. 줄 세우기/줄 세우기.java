import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

class Main {

    static int n, m;
    static int[] indegree;
    static ArrayList<ArrayList<Integer>> graph;

    private static void solve(BufferedReader br) throws IOException {
        int[] line = Arrays.stream(br.readLine().split(" "))
            .mapToInt(Integer::parseInt).toArray();
        n = line[0]; m = line[1];
        indegree = new int[n + 1];
        graph = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            graph.add(new ArrayList<>());
        }

        while (m-- > 0) {
            line = Arrays.stream(br.readLine().split(" "))
                .mapToInt(Integer::parseInt).toArray();
            graph.get(line[0]).add(line[1]);
            indegree[line[1]]++;
        }

        Queue<Integer> que = new LinkedList<>();

        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) que.add(i);
        }
        ArrayList<Integer> answer = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            int cur = que.poll();
            answer.add(cur);

            for (int nxt : graph.get(cur)) {
                indegree[nxt]--;
                if (indegree[nxt] == 0) que.add(nxt);
            }
        }

        for (int a : answer) {
            res.append(a).append(' ');
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
