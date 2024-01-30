import java.util.*;

class Solution {
    public int solution(int[] nums) {
        int answer = 0;
        int n = nums.length;
        
        Map<Integer, Integer> pon = new HashMap<>();
        for (int num : nums) {
            pon.put(num, pon.getOrDefault(num, 0) + 1);
        }
        
        int sum = 0;
        for (int key : pon.keySet()) {
            sum++;
            if (sum >= n / 2) break;
        }
        return sum;
    }
}