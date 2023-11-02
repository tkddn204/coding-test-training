import java.util.*;

class Solution {
    
    ArrayList<Integer> answer;
    List<ArrayList<Integer>> graph;
    int[] dist;
    
    int dstra(int n, int des) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        dist = new int[n + 1];
        Arrays.fill(dist, (int)1e9);
        
        pq.add(des);
        dist[des] = 0;
        while (!pq.isEmpty()) {
            int cur = pq.poll();
            
            for (int nxt : graph.get(cur)) {
                int ndist = dist[cur] + 1;
                if (ndist < dist[nxt]) {
                    dist[nxt] = ndist;
                    pq.add(nxt);
                }
            }
        }
        
        return dist[des];
    }
    
    public int[] solution(int n, int[][] roads, int[] sources, int destination) {
        answer = new ArrayList<>();
        graph = new ArrayList<>();
        for (int i = 0; i <= n; i++) graph.add(new ArrayList<>());
        
        for (int i = 0; i < roads.length; i++) {
            graph.get(roads[i][0]).add(roads[i][1]);
            graph.get(roads[i][1]).add(roads[i][0]);
        }
        dstra(n, destination);
        for (int i = 0; i < sources.length; i++) {
            int d = dist[sources[i]];
            if (d == (int)1e9) d = -1;
            answer.add(d);
        }
        
        return answer.stream().mapToInt(Integer::intValue).toArray();
    }
}