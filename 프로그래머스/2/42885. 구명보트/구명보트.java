import java.util.*;

class Solution {
    public int solution(int[] people, int limit) {
        int answer = 0;
        Arrays.sort(people);
        
        int st = 0, en = people.length - 1;
        while (st < en) {
            if (people[st] + people[en] <= limit) {
                st++;
                answer++;
            }
            en--;
        }
        
        return people.length - answer;
    }
}