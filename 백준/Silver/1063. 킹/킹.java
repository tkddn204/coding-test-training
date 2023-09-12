import java.io.*;

class Main {

    private static void solve(BufferedReader br) throws IOException {
        String[] line = br.readLine().split(" ");
        String king = line[0]; String stone = line[1];
        int n = Integer.parseInt(line[2]);

        while (n-- > 0) {
            String s = br.readLine();
            int nx = 0, ny = 0;
            for (char c : s.toCharArray()) {
                if (c == 'R') nx++;
                else if (c == 'L') nx--;
                else if (c == 'B') ny--;
                else if (c == 'T') ny++;
            }
            char kingnx = (char) (king.charAt(0) + nx);
            char kingny = (char) (king.charAt(1) + ny);
            if (!isInRange(kingnx, kingny)) continue;
            if (kingnx == stone.charAt(0) && kingny == stone.charAt(1)) {
                char stonenx = (char) (stone.charAt(0) + nx);
                char stoneny = (char) (stone.charAt(1) + ny);
                if (!isInRange(stonenx, stoneny)) continue;
                stone = stonenx + "" + stoneny;
            }
            king = kingnx + "" + kingny;
        }
        res.append(king).append('\n').append(stone);
    }

    private static boolean isInRange(char nx, char ny) {
        return nx >= 'A' && nx <= 'H' && ny >= '1' && ny <= '8';
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
