class Solution {
    
    int[] times;
    
    public boolean go(long n, long mid) {
        long res = 0;
        for (int time: times) {
            res += mid / time;
            if (res >= n) return false;
        }
        return res < n;
    }
    
    public long solution(int n, int[] _times) {
        long answer = 0;
        times = _times;
        int size = _times.length;
        
        long st = 0;
        long en = Long.MAX_VALUE - 1;
        while (st < en) {
            long mid = (st + en + 1) / 2;
            if (go((long) n, mid)) st = mid;
            else {
                en = mid - 1;
                answer = mid;
            }
        }
        
        return answer;
    }
}