import java.io.*;
import java.util.Arrays;
import java.util.function.ToIntFunction;

class Main {

    static int n, m, r;
    static int[][] arr;
    static int[] dx = {1, 0, -1, 0};
    static int[] dy = {0, 1, 0, -1};

    private static void solve(BufferedReader br) throws IOException {
        int[] inp = Arrays.stream(br.readLine().split(" "))
            .mapToInt(Integer::parseInt).toArray();
        n = inp[0]; m = inp[1]; r = inp[2];
        arr = new int[n][m];
        for (int i = 0; i < n; i++) {
            arr[i] = Arrays.stream(br.readLine().split(" "))
                .mapToInt(Integer::parseInt).toArray();
        }

        while (r-- > 0) rotate(0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res.append(arr[i][j]).append(' ');
            }
            res.append('\n');
        }
    }

    private static void rotate(int k) {
        int nlimit = n - (k * 2) + k;
        int mlimit = m - (k * 2) + k;
        if (nlimit <= k || mlimit <= k) return;

        int nx = k, ny = k;
        int d = 0;
        int val = arr[k][k];
        while (true) {
            nx += dx[d];
            ny += dy[d];
            if (nx < k || nx >= nlimit || ny < k || ny >= mlimit) {
                nx -= dx[d];
                ny -= dy[d];
                d++;
                continue;
            }
            int temp = arr[nx][ny];
            arr[nx][ny] = val;
            val = temp;
            if (nx == k && ny == k) break;
        }

        rotate(k + 1);
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
