import java.util.*;

class Solution {
    
    public int solution(int[] ingredient) {
        int answer = 0;
        
        Stack<Integer> st = new Stack<>();
        
        int idx = 0;
        int[] order = {1, 3, 2, 1};
        
        for (int ing : ingredient) {
            st.push(ing);
            if (st.size() >= 4) {
                boolean good = true;
                for (int i = 0; i < 4; i++) {
                    if (st.get(st.size() - 1 - i) != order[i]) {
                        good = false;
                        break;
                    }
                }
                if (good) {
                    int t = 4;
                    while (t-- > 0) st.pop();
                    answer++;
                }
            }
        }
        
        return answer;
    }
}