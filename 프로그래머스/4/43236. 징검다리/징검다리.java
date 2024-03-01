import java.util.*;
import java.util.stream.*;

class Solution {
    int[] rocks;
    
    boolean go(int mid, int distance, int n) {
        int pre = 0;
        int cnt = 0;
        for (int rock: rocks) {
            if (rock - pre < mid) cnt++;
            else pre = rock;
        }
        if (distance - pre < mid) cnt++;
        return cnt <= n;
    }
    
    public int solution(int distance, int[] _rocks, int n) {
        int answer = 0;
        Arrays.sort(_rocks);
        rocks = _rocks;
        
        int st = 1;
        int en = distance;
        
        while (st < en) {
            int mid = (st + en + 1) / 2;
            if (go(mid, distance, n)) st = mid;
            else en = mid - 1;
        }
        return en;
    }
}