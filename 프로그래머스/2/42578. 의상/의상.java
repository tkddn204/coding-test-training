import java.util.*;

class Solution {
    
    public int solution(String[][] clothes) {
        int answer = 1;
        Map<String, Integer> m = new HashMap<>();
        for (String[] clothe : clothes) {
            m.put(clothe[1], m.getOrDefault(clothe[1], 0) + 1);
        }
        for (int v : m.values()) answer *= v + 1;
        return answer - 1;
    }
}