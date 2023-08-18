import java.io.*;
import java.util.*;

class Main {

    static class Problem implements Comparable<Problem> {
        int num;
        int difficulty;

        public Problem(int num, int difficulty) {
            this.num = num;
            this.difficulty = difficulty;
        }

        @Override
        public int compareTo(Problem o) {
            if (this.difficulty == o.difficulty) {
                return o.num - this.num;
            }
            return o.difficulty - this.difficulty;
        }

        @Override
        public String toString() {
            return Integer.toString(this.num);
        }
    }

    static int[] difficulty;
    static PriorityQueue<Problem> ascProblem;
    static PriorityQueue<Problem> descProblem;
    private static void solve(BufferedReader br) throws IOException {
        int n = Integer.parseInt(br.readLine());
        difficulty = new int[100001];
        ascProblem = new PriorityQueue<>();
        descProblem = new PriorityQueue<>(Collections.reverseOrder());
        for (int i = 0; i < n; i++) {
            int[] inp = Arrays.stream(br.readLine().split(" "))
                .mapToInt(Integer::parseInt).toArray();
            Problem p = new Problem(inp[0], inp[1]);
            difficulty[p.num] = p.difficulty;
            ascProblem.add(p);
            descProblem.add(p);
        }
        int m = Integer.parseInt(br.readLine());
        while (m-- > 0) {
            String[] inp = br.readLine().split(" ");
            String op = inp[0];
            if (op.equals("recommend")) {
                Problem p;
                if (inp[1].equals("1")) { // 가장 어려운 문제
                    while (true) {
                        p = ascProblem.peek();
                        if (difficulty[p.num] == p.difficulty) break;
                        ascProblem.poll();
                    }
                } else { // 가장 쉬운 문제
                    while (true) {
                        p = descProblem.peek();
                        if (difficulty[p.num] == p.difficulty) break;
                        descProblem.poll();
                    }
                }
                res.append(p).append('\n');
            } else if (op.equals("add")) { // 추가
                int a = Integer.parseInt(inp[1]);
                int b = Integer.parseInt(inp[2]);
                Problem p = new Problem(a, b);
                difficulty[p.num] = p.difficulty;
                ascProblem.add(p);
                descProblem.add(p);
            } else { // 제거
                int num = Integer.parseInt(inp[1]);
                difficulty[num] = 0;
            }
        }
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
