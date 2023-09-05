import java.io.*;
import java.util.*;

class Main {

    static class Pair {
        int x,y;
        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static int n, l;
    static List<Pair> water;

    private static void solve(BufferedReader br) throws IOException {
        int[] inp = Arrays.stream(br.readLine().split(" "))
            .mapToInt(Integer::parseInt).toArray();
        n = inp[0]; l = inp[1];
        water = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int[] line = Arrays.stream(br.readLine().split(" "))
                .mapToInt(Integer::parseInt).toArray();
            water.add(new Pair(line[0], line[1]));
        }
        water.sort((a, b) -> a.x - b.x);

        int st = 0;
        int cnt = 0;
        for (Pair w : water) {
            if (st >= w.y) continue;
            st = Math.max(st, w.x);
            int need = 1 + ((w.y - 1) - st) / l;
            st += need * l;
            cnt += need;
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
