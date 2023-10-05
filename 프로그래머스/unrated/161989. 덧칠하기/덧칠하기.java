class Solution {
    public int solution(int n, int m, int[] section) {
        int answer = 0;
        int[] wall = new int[n + 1];
        for (int sec : section) wall[sec] = 1;
        
        int paint = 0;
        for (int i = 1; i <= n; i++) {
            if (paint-- > 0 || wall[i] == 0) continue;
            answer++;
            paint = m - 1;
        }
        
        return answer;
    }
}