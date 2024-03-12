import java.util.*;

class Solution {
    
    String[] orders;
    int[] course;
    Map<String, Integer> map;
    Map<String, Boolean> chk;
    
    String sortedStr(String s) {
        char[] c = s.toCharArray();
        Arrays.sort(c);
        return String.valueOf(c);
    }
    
    void go(String s, int k, int o, int cur) {
        if (k == 0) {
            String ss = sortedStr(s);
            if (!chk.getOrDefault(ss, false)) {
                map.put(ss, map.getOrDefault(ss, 0) + 1);
                chk.put(ss, true);
            }
            return;
        }
        
        for (int i = cur; i < orders[o].length(); i++) {
            go(s + orders[o].charAt(i), k - 1, o, i + 1);
            go(s, k, o, i + 1);
        }
    }
    
    public String[] solution(String[] _orders, int[] _course) {
        orders = _orders;
        course = _course;
        List<String> answer = new ArrayList<>();
        
        for (int c : course) {
            map = new HashMap<>();
            for (int i = 0; i < orders.length; i++) {
                chk = new HashMap<>();
                go("", c, i, 0);
            }
            if (map.keySet().isEmpty()) continue;
            List<String> keySet = new ArrayList<>(map.keySet());
            keySet.sort((a, b) -> Integer.compare(map.get(b), map.get(a)));
            
            int mx = map.get(keySet.get(0));
            if (mx < 2) continue;
            for (String key: keySet) {
                if (map.get(key) == mx) {
                    answer.add(key);
                } else break;
            }
        }
        answer.sort((a, b) -> a.compareTo(b));
        return answer.toArray(new String[0]);
    }
}