import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

class Main {

    private static int n;
    private static boolean[] vst;
    private static int[][] status;
    private static int minDiff = Integer.MAX_VALUE;

    private static void backtracking(int k, int x) {
        if (k == n / 2) {
            int st = 0, lk = 0;
            int[] stTeam = new int[n / 2];
            int[] lkTeam = new int[n / 2];
            int stTeamIdx = 0, lkTeamIdx = 0;
            for (int i = 1; i <= n; i++) {
                if (vst[i]) stTeam[stTeamIdx++] = i;
                else lkTeam[lkTeamIdx++] = i;
            }
            for (int i = 0; i < (n / 2) - 1; i++) {
                int a = stTeam[i];
                int c = lkTeam[i];
                for (int j = i + 1 ; j < (n / 2); j++) {
                    int b = stTeam[j];
                    int d = lkTeam[j];
                    st += status[a][b] + status[b][a];
                    lk += status[c][d] + status[d][c];
                }
            }
            minDiff = Math.min(minDiff, Math.abs(st - lk));
            return;
        }

        for (int i = x; i <= n; i++) {
            vst[i] = true;
            backtracking(k + 1, i + 1);
            vst[i] = false;
        }
    }

    private static void solve(BufferedReader br) throws IOException {
        n = Integer.parseInt(br.readLine());
        vst = new boolean[n + 1];
        status = new int[n + 1][n + 1];
        for (int i = 1; i <= n; i++) {
            StringBuilder builder = new StringBuilder(br.readLine());
            builder.insert(0, "0 ");
            int[] inp = Arrays.stream(builder.toString().split(" "))
                .mapToInt(Integer::parseInt).toArray();
            System.arraycopy(inp, 0, status[i], 0, n + 1);
        }
        backtracking(0, 1);
        res.append(minDiff);
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
