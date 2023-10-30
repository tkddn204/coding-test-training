import java.util.*;

class Solution {
    public String solution(String number, int k) {
        StringBuilder answer = new StringBuilder();
        char[] arr = number.toCharArray();
        
        int st = 0;
        for (int i = 0; i < arr.length - k; i++) {
            char mc = '0';
            for (int j = st; j <= i + k; j++) {
                if (arr[j] > mc) {
                    mc = arr[j];
                    st = j + 1;
                }
            }
            answer.append(mc);
        }
        
        return answer.toString();
    }
}