import java.io.*;
import java.util.*;

class Solution {
    public String solution(String[] survey, int[] choices) {
        String answer = "";
        
        Map<Character, Integer> map = new HashMap<>();
        
        for (int i = 0; i < survey.length; i++) {
            String s = survey[i];
            char a = s.charAt(0);
            char b = s.charAt(1);
            if (choices[i] < 4) map.put(a, map.getOrDefault(a, 0) + 4 - choices[i]);
            if (choices[i] > 4) map.put(b, map.getOrDefault(b, 0) + choices[i] - 4);
        }
        
        String[] chk = {"RT", "CF", "JM", "AN"};
        for (String k : chk) {
            char a = k.charAt(0);
            char b = k.charAt(1);
            int anum = map.getOrDefault(a, 0);
            int bnum = map.getOrDefault(b, 0);
            if (anum > bnum) answer += a;
            else if (anum < bnum) answer += b;
            else answer += a;
        }
        
        return answer;
    }
}