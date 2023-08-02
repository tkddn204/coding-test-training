class Solution {
    public int[] solution(int[] sequence, int k) {
        int n = sequence.length;
        int[] arr = new int[n + 1];
        for (int i = 0; i < n; i++) {
            arr[i] = sequence[i];
        }
        arr[n] = 0;
        long sum = 0;
        int ast = 0, aen = 0, len = 1000001;
        int en = 0;
        for (int st = 0; st < n; st++) {
            while (en <= n && sum <= k) {
                if (sum == k && len > en - st) {
                    ast = st;
                    aen = en - 1;
                    len = en - st;
                }
                sum += arr[en];
                en++;
            }
            if (en == n + 1) break;
            sum -= arr[st];
        }
        
        int[] answer = {ast, aen};
        return answer;
    }
}