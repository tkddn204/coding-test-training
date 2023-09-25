import java.io.*;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Deque;

class Main {

    static int n, k;

    private static void solve(BufferedReader br) throws IOException {
        int[] line = Arrays.stream(br.readLine().split(" "))
            .mapToInt(Integer::parseInt).toArray();
        n = line[0]; k = line[1];

        Deque<Integer> deque = new ArrayDeque<>();

        for (int i = 1; i <= n; i++) deque.add(i);

        ArrayList<Integer> list = new ArrayList<>();
        while (n-- > 0) {
            for (int i = 0; i < k - 1; i++) {
                deque.addLast(deque.pollFirst());
            }
            list.add(deque.pollFirst());
        }
        res.append("<");
        for (int i = 0; i < list.size(); i++) {
            res.append(list.get(i));
            if (i != list.size() - 1) res.append(", ");
        }
        res.append(">");
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
