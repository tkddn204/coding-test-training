import java.util.*;

class Solution {
    public int[] solution(String[] keymap, String[] targets) {
        Map<Character, Integer> map = new HashMap<>();
        
        for (String k : keymap) {
            for (int i = 0; i < k.length(); i++) {
                char cur = k.charAt(i);
                if (map.getOrDefault(cur, i + 1) >= i + 1) {
                    map.put(cur, i + 1);
                }
            }
        }
        
        List<Integer> answer = new ArrayList<>();
        
        for (String t : targets) {
            int sum = 0;
            for (char c : t.toCharArray()) {
                if (!map.containsKey(c)) {
                    sum = -1;
                    break;
                }
                sum += map.get(c);
            }
            answer.add(sum);
        }
        
        return answer.stream().mapToInt(Integer::intValue).toArray();
    }
}