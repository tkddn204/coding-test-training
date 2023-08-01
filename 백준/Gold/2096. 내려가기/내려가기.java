import java.io.*;
import java.util.*;

class Main {

    private static int[] arr = new int[4];
    private static int[][] maxDP = new int[2][4];
    private static int[][] minDP = new int[2][4];

    private static void solve(BufferedReader br) throws IOException {
        int n = Integer.parseInt(br.readLine());
        for (int i = 1; i <= n; i++) {
            String[] inp = br.readLine().split(" ");
            for (int j = 1; j <= 3; j++) {
                arr[j] = Integer.parseInt(inp[j - 1]);
                maxDP[0][j] = maxDP[1][j];
                minDP[0][j] = minDP[1][j];
            }

            maxDP[1][1] = Math.max(maxDP[0][1] + arr[1], maxDP[0][2] + arr[1]);
            maxDP[1][2] = Math.max(maxDP[0][1] + arr[2], Math.max(maxDP[0][2] + arr[2], maxDP[0][3] + arr[2]));
            maxDP[1][3] = Math.max(maxDP[0][2] + arr[3], maxDP[0][3] + arr[3]);

            minDP[1][1] = Math.min(minDP[0][1] + arr[1], minDP[0][2] + arr[1]);
            minDP[1][2] = Math.min(minDP[0][1] + arr[2], Math.min(minDP[0][2] + arr[2], minDP[0][3] + arr[2]));
            minDP[1][3] = Math.min(minDP[0][2] + arr[3], minDP[0][3] + arr[3]);
        }
        int maxVal = 0, minVal = Integer.MAX_VALUE;
        for (int i = 1; i <= 3; i++) {
            maxVal = Math.max(maxVal, maxDP[1][i]);
            minVal = Math.min(minVal, minDP[1][i]);
        }
        res.append(maxVal).append(' ').append(minVal);
    }

    private static StringBuilder res;
    public static void main(String args[]) throws Exception {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))) {
            res = new StringBuilder();
            solve(br);
            bw.write(res.toString());
        }
    }
}
