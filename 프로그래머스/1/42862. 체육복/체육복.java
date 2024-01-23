import java.util.*;

class Solution {
    int[] st;
    public int solution(int n, int[] lost, int[] reserve) {
        int answer = 0;
        Set<Integer> l = new HashSet<>();
        Set<Integer> r = new HashSet<>();
        
        for (int i : reserve) r.add(i);
        for (int i : lost) {
            if (r.contains(i)) r.remove(i);
            else l.add(i);
        }
        
        for (int i : r) {
            if (l.contains(i - 1)) l.remove(i - 1);
            else if (l.contains(i + 1)) l.remove(i + 1);
        }
        
        return n - l.size();
    }
}