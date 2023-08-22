import java.io.*;
import java.util.*;

class Main {

    static int n, k;
    static int[] tree;
    static int cnt;

    private static void remove(int root) {
        tree[root] = -1;

        ArrayList<Integer> child = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (tree[i] == root) child.add(i);
        }

        for (int c : child) remove(c);
    }

    private static void leaf(int root) {
        ArrayList<Integer> child = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (tree[i] == root) child.add(i);
        }

        if  (child.isEmpty()) {
            cnt++;
            return;
        }

        for (int c : child) leaf(c);
    }

    private static void solve(BufferedReader br) throws IOException {
        n = Integer.parseInt(br.readLine());

        int root = -1;
        tree = Arrays.stream(br.readLine().split(" "))
            .mapToInt(Integer::parseInt).toArray();
        for (int i = 0; i < n; i++) {
            if (tree[i] == -1) root = i;
        }
        k = Integer.parseInt(br.readLine());

        if (k != root) {
            remove(k);
            leaf(root);
        }

        res.append(cnt);
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
