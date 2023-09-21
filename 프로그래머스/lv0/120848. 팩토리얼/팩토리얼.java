class Solution {
    public int solution(int n) {
        int answer = 1, k = 1;
        while(n >= k) k *= ++answer;
        return answer - 1;
    }
}