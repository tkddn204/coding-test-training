import java.io.*;
import java.util.*;

class Main {

    static String s, e, q;

    private static void solve(BufferedReader br) throws IOException {
        String[] inp = br.readLine().split(" ");
        s = inp[0]; e = inp[1]; q = inp[2];

        int st = getTime(s);
        int et = getTime(e);
        int qt = getTime(q);

        HashMap<String, Integer> inMap = new HashMap<>();
        HashMap<String, Integer> outMap = new HashMap<>();

        String line = "";
        while ((line = br.readLine()) != null) {
            String[] splited = line.split(" ");
            int time = getTime(splited[0]);
            String name = splited[1];

            if (time <= st) inMap.put(name, time);
            else if (time >= et && time <= qt) {
                if (inMap.containsKey(name)) outMap.put(name, time);
            }
        }
        res.append(outMap.keySet().size());
    }

    private static int getTime(String s) {
        String[] splited = s.split(":");
        return Integer.parseInt(splited[0]) * 60 + Integer.parseInt(splited[1]);
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
