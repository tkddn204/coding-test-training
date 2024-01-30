import java.util.*;

class Solution {
    public int solution(int[] nums) {
        int answer = 0;
        int n = nums.length;
        
        Map<Integer, Integer> pon = new HashMap<>();
        for (int num : nums) {
            pon.put(num, pon.getOrDefault(num, 0) + 1);
        }
        
        List<Integer> keys = new ArrayList<>(pon.keySet());
        keys.sort((a, b) -> pon.get(a).compareTo(pon.get(b)));
        
        int sum = 0;
        for (int key : keys) {
            sum++;
            if (sum >= n / 2) break;
        }
        
        // 포켓몬 종류 번호 갯수
        
        return sum;
    }
}