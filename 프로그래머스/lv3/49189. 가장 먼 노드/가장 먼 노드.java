import java.util.*;

class Solution {
    class Edge implements Comparable<Edge> {
        int x, cost;
        public Edge(int x, int cost) {
            this.x = x;
            this.cost = cost;
        }
        public int compareTo(Edge e) {
            return this.cost - e.cost;
        }
    }
    
    ArrayList<ArrayList<Integer>> graph;
    int[] dist;
    
    public int solution(int n, int[][] edge) {
        int answer = 0;
        
        graph = new ArrayList<>();
        dist = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            graph.add(new ArrayList<>());
            dist[i] = (int)1e9;
        }
        for (int[] e : edge) {
            graph.get(e[0]).add(e[1]);
            graph.get(e[1]).add(e[0]);
        }
        
        PriorityQueue<Edge> pq = new PriorityQueue<>();
        pq.add(new Edge(1, 0));
        dist[1] = 0;
        
        int mxDist = 0;
        
        while (!pq.isEmpty()) {
            Edge cur = pq.poll();
            
            for (int nxt: graph.get(cur.x)) {
                int nc = cur.cost + 1;
                if (nc < dist[nxt]) {
                    pq.add(new Edge(nxt, nc));
                    dist[nxt] = nc;
                    mxDist = Math.max(mxDist, nc);
                }
            }
        }
        
        for (int i = 1; i <= n; i++) {
            if (dist[i] == mxDist) answer++;
        }
        
        return answer;
    }
}