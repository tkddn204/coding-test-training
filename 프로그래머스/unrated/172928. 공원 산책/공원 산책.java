class Solution {
    int[] dx = {-1, 1, 0, 0};
    int[] dy = {0, 0, -1, 1};
    public int[] solution(String[] park, String[] routes) {
        int r = -1, c = -1;
        int n = park.length;
        int m = park[0].length();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (park[i].charAt(j) == 'S') {
                    r = i;
                    c = j;
                    break;
                }
            }
        }
        
        for (String route : routes) {
            String[] splited = route.split(" ");
            int d = 0;
            if (splited[0].equals("N")) d = 0;
            else if (splited[0].equals("S")) d = 1;
            else if (splited[0].equals("W")) d = 2;
            else d = 3;
            int move = Integer.parseInt(splited[1]);
            int nx = r, ny = c;
            boolean possible = true;
            while (move-- > 0) {
                nx += dx[d];
                ny += dy[d];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || park[nx].charAt(ny) == 'X') {
                    possible = false;
                    break;
                }
            }
            if (possible) {
                r = nx;
                c = ny;
            }
        }
        
        return new int[]{r, c};
    }
}