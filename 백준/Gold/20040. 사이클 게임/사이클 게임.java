import java.io.*;
import java.util.Arrays;
import java.util.stream.IntStream;

class Main {

    static int n, m;
    static int[] parent;

    private static void solve(BufferedReader br) throws IOException {
        int[] inp = Arrays.stream(br.readLine().split(" "))
            .mapToInt(Integer::parseInt).toArray();
        n = inp[0]; m = inp[1];

        parent = new int[n + 1];
        IntStream.range(0, n + 1).forEach(i -> parent[i] = i);

        int turn = 1;
        while (m-- > 0) {
            int[] line = Arrays.stream(br.readLine().split(" "))
                .mapToInt(Integer::parseInt).toArray();
            if (getParent(line[0]) == getParent(line[1])) {
                res.append(turn);
                return;
            }
            unionParent(line[0], line[1]);
            turn++;
        }
        res.append(0);
    }

    static int getParent(int x) {
        if (x == parent[x]) return x;
        return parent[x] = getParent(parent[x]);
    }

    static void unionParent(int a, int b) {
        a = parent[a];
        b = parent[b];
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
