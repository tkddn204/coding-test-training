import java.util.*;

class Solution {
    
    int[] parent;
    
    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    
    void union(int a, int b) {
        a = find(a);
        b = find(b);
        
        if (a < b) parent[b] = a;
        else parent[a] = b;
    }
    
    public int solution(int[] cards) {
        int n = cards.length;
        parent = new int[n + 1];
        for (int i = 1; i <= n; i++) parent[i] = i;
        for (int i = 1; i <= n; i++) union(i, cards[i - 1]);
        for (int i = 1; i <= n; i++) union(i, parent[i]);
        int[] set = new int[n + 1];
        for (int i = 1; i <= n; i++) set[parent[i]]++;
        Arrays.sort(set);
        return set[n] * set[n - 1];
    }
}