import java.util.*;

class Solution {
    public int solution(int[][] board, int[] moves) {
        int answer = 0;
        int n = board.length;
        int m = board[0].length;
        
        Stack<Integer> stack = new Stack();
        for (int move : moves) {
            move--;
            int cur = 0;
            while (cur < m && board[cur][move] == 0) cur++;
            if (cur == m) continue;
            int val = board[cur][move];
            board[cur][move] = 0;
            if (!stack.empty() && stack.peek() == val) {
                stack.pop();
                answer += 2;
            } else {
                stack.push(val);
            }
        }
        
        return answer;
    }
}