class Solution {
    public int[] solution(String[] wallpaper) {
        int[] answer = {};
        int n = wallpaper.length;
        int m = wallpaper[0].length();
        
        int minx = 51, miny = 51, maxx = 0, maxy = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (wallpaper[i].charAt(j) == '#') {
                    minx = Math.min(minx, i);
                    miny = Math.min(miny, j);
                    maxx = Math.max(minx, i);
                    maxy = Math.max(maxy, j);
                }
            }
        }
        return new int[]{minx, miny, maxx + 1, maxy + 1};
    }
}