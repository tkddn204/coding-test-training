class Solution {
    
    public String solution(String s, String skip, int index) {
        String answer = "";
        
        String chk = "";
        for (char c = 'a'; c <= 'z'; c++) {
            if (skip.indexOf(c) > -1) continue;
            chk += c;
        }
        for (char c : s.toCharArray()) {
            answer += chk.charAt((chk.indexOf(c) + index) % chk.length());
        }
        
        return answer;
    }
}