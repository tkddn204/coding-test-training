import java.util.*;

class Solution {
    class Pair {
        int x, y;
        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    HashMap<Integer, Pair> map = new HashMap<>();
    int[] leftKeys = {1, 4, 7};
    int[] rightKeys = {3, 6, 9};
    public String solution(int[] numbers, String hand) {
        String answer = "";
        
        map.put(1, new Pair(0, 0)); map.put(2, new Pair(0, 1)); map.put(3, new Pair(0, 2));
        map.put(4, new Pair(1, 0)); map.put(5, new Pair(1, 1)); map.put(6, new Pair(1, 2));
        map.put(7, new Pair(2, 0)); map.put(8, new Pair(2, 1)); map.put(9, new Pair(2, 2));
        map.put(10, new Pair(3, 0)); map.put(0, new Pair(3, 1)); map.put(11, new Pair(3, 2));
        
        int left = 10;
        int right = 11;
        
        for (int number : numbers) {
            if (Arrays.stream(leftKeys).anyMatch(i -> i == number)) {
                answer += 'L';
                left = number;
            } else if (Arrays.stream(rightKeys).anyMatch(i -> i == number)) {
                answer += 'R';
                right = number;
            } else {
                int leftdis = 0, rightdis = 0;
                leftdis += Math.abs(map.get(number).x - map.get(left).x);
                leftdis += Math.abs(map.get(number).y - map.get(left).y);
                rightdis += Math.abs(map.get(number).x - map.get(right).x);
                rightdis += Math.abs(map.get(number).y - map.get(right).y);
                if (leftdis == rightdis) {
                    if (hand.equals("left")) {
                        answer += 'L';
                        left = number;
                    } else {
                        answer += 'R';
                        right = number;
                    }
                } else if (leftdis < rightdis) {
                    answer += 'L';
                    left = number;
                } else {
                    answer += 'R';
                    right = number;
                }
            }
        }
        
        return answer;
    }
}