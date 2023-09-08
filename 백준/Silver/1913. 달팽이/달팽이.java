import java.io.*;

class Main {

    static int n, k;
    static int[][] snail;
    private static void solve(BufferedReader br) throws IOException {
        n = Integer.parseInt(br.readLine());
        k = Integer.parseInt(br.readLine());

        snail = new int[n][n];

        int num = 1;
        int x = n / 2;
        int y = n / 2 - (n % 2 == 0 ? 1: 0);
        snail[x][y] = num++;
        x--;
        for (int k = 2; k <= n; k++) {
            int until;
            if (k % 2 == 0) {
                until = y + k;
                for (; y < until; y++) {
                    snail[x][y] = num++;
                }
                until = x + k;
                x++; y--;
                for (; x <= until; x++) {
                    snail[x][y] = num++;
                }
                x--;
            } else {
                until = y - k;
                y--;
                for (; y > until; y--) {
                    snail[x][y] = num++;
                }
                until = x - k;
                x--; y++;
                for (; x > until; x--) {
                    snail[x][y] = num++;
                }
            }
        }
        int resX = 0, resY = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res.append(snail[i][j]).append(' ');
                if (snail[i][j] == k) {
                    resX = i + 1;
                    resY = j + 1;
                }
            }
            res.append('\n');
        }
        res.append(resX).append(' ').append(resY);
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
