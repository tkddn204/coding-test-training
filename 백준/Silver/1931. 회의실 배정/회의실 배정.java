import java.io.*;
import java.util.*;

class Main {

    static class Room {
        int st, en;
        Room(int st, int en) {
            this.st = st;
            this.en = en;
        }
    }

    private static void solve(BufferedReader br) throws IOException {
        int n = Integer.parseInt(br.readLine());
        List<Room> list = new ArrayList<>();
        while (n-- > 0) {
            int[] inp = Arrays.stream(br.readLine().split(" "))
                .mapToInt(Integer::parseInt).toArray();
            list.add(new Room(inp[0], inp[1]));
        }
        list.sort((a, b) -> {
            if (a.en == b.en) return Integer.compare(a.st, b.st);
            return Integer.compare(a.en, b.en);
        });

        int cnt = 0;
        int t = 0;
        for (Room r : list) {
            if (t <= r.st) {
                cnt++;
                t = r.en;
            }
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
