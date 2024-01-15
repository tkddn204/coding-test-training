import java.util.*;

class Solution {
    public int solution(int[] bandage, int health, int[][] attacks) {
        int answer = health;
        int last = attacks[attacks.length - 1][0];
        
        int ai = 0, bi = 0;
        for (int t = 1; t <= last; t++) {
            if (attacks[ai][0] == t) {
                answer -= attacks[ai][1];
                ai++;
                bi = 0;
                if (answer <= 0) return -1;
            } else {
                answer = Math.min(health, answer + bandage[1]);
                bi++;
                if (bi == bandage[0]) {
                    answer = Math.min(health, answer + bandage[2]);
                    bi = 0;
                }
            }
        }
        if (answer <= 0) return -1;
        else return answer;
    }
}