import java.util.*;

class Solution {
    public long solution(int[] weights) {
        long answer = 0;
        HashMap<Double, Integer> map = new HashMap<>();
        double[] ss = new double[]{1., 1./2, 2./3, 3./4};
        
        Arrays.sort(weights);
        for (int weight: weights) {
            for (double s: ss) answer += map.getOrDefault(s * weight, 0);
            map.put((double)weight, map.getOrDefault((double)weight, 0) + 1);
        }
        return answer;
    }
}