import java.io.*;
import java.util.*;

class Main {

  static int n;
  static int[] order;
  static int[][] good;
  static int[][] empty;
  static int[][] room;
  static int[] dx = {0, 1, 0, -1};
  static int[] dy = {1, 0, -1, 0};
  static PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> {
    if (empty[a.x][a.y] == empty[b.x][b.y]) {
      if (a.x == b.x) return Integer.compare(a.y, b.y);
      return Integer.compare(a.x, b.x);
    }

    return Integer.compare(empty[b.x][b.y], empty[a.x][a.y]);
  });

  private static void solve(BufferedReader br) throws IOException {
    n = Integer.parseInt(br.readLine());
    order = new int[n * n];
    good = new int[n * n + 1][4];
    empty = new int[n * n][n * n];
    room = new int[n * n][n * n];

    for (int i = 0; i < n * n; i++) {
      int[] line = Arrays.stream(br.readLine().split(" "))
          .mapToInt(Integer::parseInt).toArray();
      order[i] = line[0];
      for (int j = 0; j < 4; j++) {
        good[order[i]][j] = line[j + 1];
      }
    }

    for (int i = 0; i < n * n; i++) {
      checkEmpty();
      int st = order[i];
      checkGood(st);
      Pair nxt = pq.peek();
      room[nxt.x][nxt.y] = st;
//      printRoom();
    }

    res.append(satisfy());
  }

  private static void printRoom() {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        res.append(room[i][j]).append(' ');
      }
      res.append('\n');
    }
    res.append("-------------").append('\n');
  }


  private static void checkEmpty() {
    for (int x = 0; x < n; x++) {
      for (int y = 0; y < n; y++) {
        int cnt = 0;
        for (int d = 0; d < 4; d++) {
          int nx = x + dx[d];
          int ny = y + dy[d];

          if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
          if (room[nx][ny] == 0) cnt++;
        }

        empty[x][y] = cnt;
      }
    }
  }

  private static void checkGood(int st) {
    pq.clear();
    int mx = 0;
    for (int x = 0; x < n; x++) {
      for (int y = 0; y < n; y++) {
        if (room[x][y] > 0) continue;
        int cnt = 0;
        for (int d = 0; d < 4; d++) {
          int nx = x + dx[d];
          int ny = y + dy[d];

          if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
          for (int g = 0; g < 4; g++) {
            if (good[st][g] == room[nx][ny]) cnt++;
          }
        }
        if (cnt < mx) continue;
        if (cnt > mx) {
          mx = cnt;
          pq.clear();
        }
        pq.add(new Pair(x, y));
      }
    }
  }

  private static int satisfy() {
    int sum = 0;
    for (int x = 0; x < n; x++) {
      for (int y = 0; y < n; y++) {
        int st = room[x][y];
        int cnt = 0;
        for (int d = 0; d < 4; d++) {
          int nx = x + dx[d];
          int ny = y + dy[d];

          if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
          for (int g = 0; g < 4; g++) {
            if (good[st][g] == room[nx][ny]) cnt++;
          }
        }
        if (cnt != 0) {
          int k = 1;
          while (cnt-- > 1) k *= 10;
          sum += k;
        }
      }
    }
    return sum;
  }

  static class Pair {
    int x, y;
    Pair(int x, int y) {
      this.x = x;
      this.y = y;
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
