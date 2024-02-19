class Solution {
    public String solution(String[] cards1, String[] cards2, String[] goal) {
        String answer = "Yes";
        
        int a = 0, b = 0;
        for (int g = 0; g < goal.length; g++) {
            if (a < cards1.length && goal[g].equals(cards1[a])) a++;
            else if (b < cards2.length && goal[g].equals(cards2[b])) b++;
            else {answer = "No"; break;}
        }
        
        return answer;
    }
}