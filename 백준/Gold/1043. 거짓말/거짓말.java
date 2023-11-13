import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;

class Main {

    static int n, m;
    static int[] parent;
    static ArrayList<ArrayList<Integer>> party;

    static int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    static void union(int a, int b) {
        a = find(a);
        b = find(b);

        if (a < b) parent[b] = a;
        else parent[a] = b;
    }

    private static void solve(BufferedReader br) throws IOException {
        int[] s = Arrays.stream(br.readLine().split(" "))
            .mapToInt(Integer::parseInt).toArray();
        n = s[0]; m = s[1];
        parent = new int[n + 1];
        party = new ArrayList<>();

        for (int i = 1; i <= n; i++) parent[i] = i;

        int[] line = Arrays.stream(br.readLine().split(" "))
            .mapToInt(Integer::parseInt).toArray();
        int k = line[0];
        for (int i = 1; i <= k; i++) parent[line[i]] = 0;

        for (int i = 0; i < m; i++) {
            line = Arrays.stream(br.readLine().split(" "))
                .mapToInt(Integer::parseInt).toArray();
            k = line[0];
            party.add(new ArrayList<>());
            for (int j = 1; j <= k; j++) {
                party.get(i).add(line[j]);
            }
            for (int j = 0; j < k - 1; j++) {
                union(party.get(i).get(j), party.get(i).get(j + 1));
            }
        }
        int sum = 0;
        for (ArrayList<Integer> p : party) {
            for (int a : p) {
                if (find(a) == 0) {
                    sum++;
                    break;
                }
            }
        }
        System.out.println(m - sum);
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
