import java.util.*;

class Solution {
    class Edge {
        int x, y, w;
        Edge(int x, int y, int w) {
            this.x = x;
            this.y = y;
            this.w = w;
        }
        Edge(int[] cost) {
            this.x = cost[0];
            this.y = cost[1];
            this.w = cost[2];
        }
    }
    
    int[] parent = new int[101];
    
    int find(int x) {
        if (parent[x] == x) return parent[x];
        return parent[x] = find(parent[x]);
    }
    
    void uni(int a, int b) {
        a = find(a);
        b = find(b);
        
        if (a < b) parent[b] = a;
        else parent[a] = b;
    }
    
    public int solution(int n, int[][] costs) {
        int answer = 0;
        
        for (int i = 1; i <= n; i++) parent[i] = i;
        
        List<Edge> arr = new ArrayList<>();
        for (int[] cost: costs) {
            arr.add(new Edge(cost));
        }
        arr.sort((a, b) -> Integer.compare(a.w, b.w));
        
        for (Edge e: arr) {
            if (find(e.x) == find(e.y)) continue;
            uni(e.x, e.y);
            answer += e.w;
        }
        
        return answer;
    }
}