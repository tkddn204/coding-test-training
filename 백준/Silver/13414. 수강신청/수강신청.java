import java.io.*;
import java.util.*;

class Main {

    static int k, l;

    private static void solve(BufferedReader br) throws IOException {
        int[] inp = Arrays.stream(br.readLine().split(" "))
            .mapToInt(Integer::parseInt).toArray();
        k = inp[0]; l = inp[1];

        Map<String, Integer> map = new HashMap<>();
        for (int i = 1; i <= l; i++) {
            String student = br.readLine();
            map.put(student, i);
        }
        map.entrySet().stream().sorted(Map.Entry.comparingByValue()).limit(k)
            .forEach(e -> res.append(e.getKey()).append("\n"));
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
