class Solution {
    int go(int n, int k, int[] numbers, int target) {
        if (k == numbers.length) {
            if (n == target) return 1;
            return 0;
        }   
        return go(n + numbers[k], k + 1, numbers, target) + go(n - numbers[k], k + 1, numbers, target);
    }
    
    public int solution(int[] numbers, int target) {
        return go(0, 0, numbers, target);
    }
}