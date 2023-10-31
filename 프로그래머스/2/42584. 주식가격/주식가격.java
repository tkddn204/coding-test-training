import java.util.*;

class Solution {
    public int[] solution(int[] prices) {
        int n = prices.length;
        int[] answer = new int[n];
        
        Stack<Integer> st = new Stack<>();
        for (int i = 0; i < n; i++) {
            while (!st.isEmpty() && prices[st.peek()] > prices[i]) {
                int k = st.pop();
                answer[k] = i - k;
            }
            st.push(i);
        }
        
        while (!st.isEmpty()) {
            int k = st.pop();
            answer[k] = n - 1 - k;
        }
        
        return answer;
    }
}