import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

class Main {

    private static void solve(BufferedReader br) throws IOException {
        int n = Integer.parseInt(br.readLine());
        int[] nums = new int[n];
        StringTokenizer tokenizer = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            nums[i] = Integer.parseInt(tokenizer.nextToken());
        }
        Arrays.sort(nums);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int st = 0, en = n - 1;
            while (st < en) {
                int sum = nums[st] + nums[en];
                if (nums[i] == sum) {
                    if (st != i && en != i) {
                        cnt++;
                        break;
                    }

                    // 마이너스값을 다룰 경우 생각해야되는 부분
                    if (st == i) st++;
                    if (en == i) en--;
                } else if (sum > nums[i]) en--;
                else st++;
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
