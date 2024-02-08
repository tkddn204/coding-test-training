import java.util.*;

class Solution {
    public int[] solution(int brown, int yellow) {
        int sum = brown + yellow;
        
        for (int w = 1; w < sum; w++) {
            if (sum % w > 0) continue;
            int h = sum / w;
            int y = (w - 2) * (h - 2);
            int b = sum - y;
            if (y == yellow && b == brown) {
                return new int[]{h, w};
            }
        }
        return new int[]{0, 0};
    }
}