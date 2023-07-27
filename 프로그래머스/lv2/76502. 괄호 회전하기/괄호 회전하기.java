import java.util.*;
class Solution {
    private boolean isCorrect(String s) {
        Stack<Character> stack = new Stack<>();
        for (char c: s.toCharArray()) {
            if (c == '(' || c == '[' || c == '{') {
                stack.push(c);
            } else {
                    if (stack.empty()) return false;
                if (c == ')' && stack.peek() != '(') return false;
                if (c == ']' && stack.peek() != '[') return false;
                if (c == '}' && stack.peek() != '{') return false;
                stack.pop();
            }
        }
        return stack.isEmpty();
    }
    public int solution(String s) {
        int answer = 0;
        StringBuilder sb = new StringBuilder(s);
        for (int i = 0; i < sb.length(); i++) {
                sb.append(sb.charAt(0));
                sb.deleteCharAt(0);
                if (isCorrect(sb.toString())) answer++;
        }

        return answer;
    }
}