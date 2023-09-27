import java.util.*;

class Solution {
    class Edge {
        int x, cost;
        public Edge (int x, int cost) {
            this.x = x;
            this.cost = cost;
        }
    }
    
    ArrayList<ArrayList<Edge>> graph;
    int[] dist;
    
    public int solution(int N, int[][] road, int K) {
        int answer = 0;
        graph = new ArrayList<>();
        dist = new int[N + 1];
        for (int i = 0; i <= N; i++) {
            graph.add(new ArrayList<>());
            dist[i] = Integer.MAX_VALUE;
        }
        
        for (int[] r : road) {
            graph.get(r[0]).add(new Edge(r[1], r[2]));
            graph.get(r[1]).add(new Edge(r[0], r[2]));
        }
        
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        pq.add(1);
        dist[1] = 0;
        
        while (!pq.isEmpty()) {
            int cur = pq.poll();
            
            for (Edge e: graph.get(cur)) {
                int nc = dist[cur] + e.cost;
                if (nc < dist[e.x]) {
                    pq.add(e.x);
                    dist[e.x] = nc;
                }
            }
        }
        
        for (int i = 1; i <= N; i++) {
            if (dist[i] <= K) answer++;
        }
        
        return answer;
    }
}