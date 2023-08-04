class Solution {

        int n;
        int[][] pan;
        int[] dx = {1, -1, 1, 1, -1, -1};
        int[] dy = {0, 0, 1, -1, 1, -1};

        int answer = 0;

        boolean check(int x, int y) {
            for (int d = 0; d < 6; d++) {
                int nx = x;
                int ny = y;
                while (true) {
                    nx += dx[d];
                    ny += dy[d];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) break;
                    if (pan[nx][ny] == 1) return false;
                }
            }
            return true;
        }

        void bt(int k) {
            if (k == n) {
                answer++;
                return;
            }

            for (int i = 0; i < n; i++) {
                if (pan[k][i] == 0 && check(k, i)) {
                    pan[k][i] = 1;
                    bt(k + 1);
                    pan[k][i] = 0;
                }
            }
        }
        public int solution(int n) {
            this.n = n;
            pan = new int[n][n];
            bt(0);
            return answer;
        }
    }