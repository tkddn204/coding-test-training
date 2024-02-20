class Solution {
    
    int go(long n, long l, long r) {
        if (l > r) return 0;
        if (n == 1) return 1;
        int cnt = 0;
        long nxt = n / 5;
        for (int i = 0; i < 5; i++) {
            if (i == 2) continue;
            cnt += go(nxt,
                      Math.max(nxt * i, l) - (nxt * i),
                      Math.min(nxt * (i + 1) - 1, r) - (nxt * i));
        }
        return cnt;
    }
    
    public int solution(int n, long l, long r) {
        return go((long) Math.pow(5, n), l - 1, r - 1);
    }
}