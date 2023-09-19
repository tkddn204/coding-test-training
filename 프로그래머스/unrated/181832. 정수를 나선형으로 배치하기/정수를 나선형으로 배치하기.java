class Solution {
    int[] dx = {0, 1, 0, -1};
    int[] dy = {1, 0, -1, 0};
    int d;
    
    public int[][] solution(int n) {
        int[][] answer = new int[n][n];
        
        int num = 1;
        int nx = 0;
        int ny = -1;
        while (num <= n * n) {
            nx += dx[d];
            ny += dy[d];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || answer[nx][ny] > 0) {
                nx -= dx[d];
                ny -= dy[d];
                d = (d + 1) % 4;
                continue;
            }
            
            answer[nx][ny] = num++;
        }
        
        return answer;
    }
}