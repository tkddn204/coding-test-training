import java.util.stream.*;
class Solution {
    public long solution(int k, int d) {
        return Stream.iterate(0, i -> i + k).limit(d / k + 1)
            .mapToLong(i -> (long) Math.sqrt((long)d * d - (long)i * i) / k + 1)
            .sum();
    }
}