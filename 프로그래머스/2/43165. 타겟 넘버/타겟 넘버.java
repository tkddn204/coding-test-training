class Solution {
    int answer = 0;
    void go(int n, int k, int[] numbers, int target) {
        if (k == numbers.length) {
            if (n == target) answer++;
            return;
        }
        
        go(n + numbers[k], k + 1, numbers, target);
        go(n - numbers[k], k + 1, numbers, target);
    }
    
    public int solution(int[] numbers, int target) {
        go(0, 0, numbers, target);
        
        return answer;
    }
}