import java.util.*;

class Solution {
    class Edge implements Comparable<Edge> {
        int x, fare;
        Edge(int x, int fare) {
            this.x = x;
            this.fare = fare;
        }
        
        public int compareTo(Edge e) {
            return Integer.compare(this.fare, e.fare);
        }
    }
    
    ArrayList<ArrayList<Edge>> graph;
    
    int[] dstra(int n, int s) {
        PriorityQueue<Edge> pq = new PriorityQueue<>();
        int[] cost = new int[n + 1];
        Arrays.fill(cost, (int)1e9);
        
        pq.add(new Edge(s, 0));
        cost[s] = 0;
        while (!pq.isEmpty()) {
            Edge cur = pq.poll();
            
            if (cur.fare > cost[cur.x]) continue;
            
            for (Edge nxt : graph.get(cur.x)) {
                int nfare = nxt.fare + cost[cur.x];
                if (nfare < cost[nxt.x]) {
                    pq.add(new Edge(nxt.x, nfare));
                    cost[nxt.x] = nfare;
                }
            }
        }
        
        return cost;
    }
    
    public int solution(int n, int s, int a, int b, int[][] fares) {
        int answer = (int)1e9;
        graph = new ArrayList<>(n + 1);
        for (int i = 0; i <= n; i++) {
            graph.add(new ArrayList<>());
        }
        for (int[] fare : fares) {
            graph.get(fare[0]).add(new Edge(fare[1], fare[2]));
            graph.get(fare[1]).add(new Edge(fare[0], fare[2]));
        }
        
        int[] both = dstra(n, s);
        for (int i = 1; i <= n; i++) {
            int[] one = dstra(n, i);
            if (both[i] == (int)1e9 || one[a] == (int)1e9 || one[b] == (int)1e9) continue;
            answer = Math.min(answer, both[i] + one[a] + one[b]);
        }
        
        return answer;
    }
}