import java.io.*;
import java.util.*;

class Main {

    static int n, m;
    static int[] vst;
    static int[] inps;
    static int[] nums;

    private static void recursion(int k, int x) {
        if (k == m) {
            for (int i = 0; i < m; i++) {
                res.append(nums[i]).append(' ');
            }
            res.append('\n');
            return;
        }

        for (int i = 1; i <= n; i++) {
            nums[k] = inps[i];
            recursion(k + 1, i + 1);
        }
    }

    private static void solve(BufferedReader br) throws IOException {
        int[] inp = Arrays.stream(br.readLine().split(" "))
            .mapToInt(Integer::parseInt).toArray();
        n = inp[0]; m = inp[1];
        StringBuilder sb = new StringBuilder(br.readLine());
        sb.insert(0, "0 ");
        inps = Arrays.stream(sb.toString().split(" "))
            .mapToInt(Integer::parseInt).sorted().toArray();
        nums = new int[m];
        recursion(0, 1);
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
