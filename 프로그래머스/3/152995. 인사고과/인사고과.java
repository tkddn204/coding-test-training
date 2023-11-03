import java.util.*;

class Solution {
    
    public int solution(int[][] scores) {
        int answer = 0;
        
        int[] ho = scores[0];
        int hosum = ho[0] + ho[1];
        
        Arrays.sort(scores, (a, b) -> a[0] == b[0] ? a[1] - b[1] : b[0] - a[0]);
        List<Integer> rank = new ArrayList<>();
        
        int max = 0;
        for (int[] score: scores) {
            if (score[1] < max) {
                if (ho[0] == score[0] && ho[1] == score[1]) {
                    return -1;
                }
            } else {
                rank.add(score[0] + score[1]);
                max = Math.max(max, score[1]);
            }
        }
        
        Collections.sort(rank, Collections.reverseOrder());
        answer = rank.indexOf(hosum) + 1;
        return answer;
    }
}