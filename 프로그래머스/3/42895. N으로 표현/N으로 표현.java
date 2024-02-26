import java.util.*;

class Solution {
    
    void union(Set<Integer> set, Set<Integer> a, Set<Integer> b) {
        for (int x: a) {
            for (int y: b) {
                set.add(x + y);
                set.add(x - y);
                set.add(x * y);
                if (y != 0) set.add(x / y);
            }
        }
    }
    
    public int solution(int N, int number) {
        if (N == number) return 1;
        
        List<Set<Integer>> dp = new ArrayList<>();
        
        for (int i = 0; i < 9; i++) dp.add(new HashSet<>());
        dp.get(1).add(N);
        
        for (int i = 2; i <= 8; i++) {
            for (int j = 1; j <= i / 2; j++) {
                union(dp.get(i), dp.get(i - j), dp.get(j));
                union(dp.get(i), dp.get(j), dp.get(i - j));
            }
            String n = String.valueOf(N);
            dp.get(i).add(Integer.parseInt(n.repeat(i)));
            for (int num : dp.get(i)) {
                if (num == number) return i;
            }
        }
        
        return -1;
    }
}