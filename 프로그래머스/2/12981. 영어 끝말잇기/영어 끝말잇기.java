import java.util.*;

class Solution {
    public int[] solution(int n, String[] words) {
        int[] answer = new int[]{0, 0};
        Map<String, Boolean> map = new HashMap<>();
        
        int p = 0;
        int o = 1;
        String pre = "";
        for (String word: words) {
            boolean bw = map.containsKey(word);
            boolean bp = pre != "" && pre.charAt(pre.length() - 1) != word.charAt(0);
            if (bw || bp) {
                answer[0] = p + 1;
                answer[1] = o;
                break;
            } else map.put(word, true);
            p = (p + 1) % n;
            if (p == 0) o++;
            pre = word;
        }
        
        return answer;
    }
}