import java.util.*;

class Solution {
    
    HashMap<String, ArrayList<Integer>> map;
    
    public int[] solution(String[] info, String[] query) {
        int[] answer = new int[query.length];
        map = new HashMap<>();
        
        for (String x : info) {
            dfs(0, "", x.split(" "));
        }
        
        for (ArrayList<Integer> list : map.values()) {
            Collections.sort(list);
        }
        
        for (int i = 0; i < query.length; i++) {
            String[] q = query[i].replaceAll(" and ", "").split(" ");
            if (map.containsKey(q[0])) {
                answer[i] = binarySearch(q[0], Integer.parseInt(q[1]));
            } else {
                answer[i] = 0;
            }
        }
        
        return answer;
    }
    
    private void dfs(int k, String query, String[] info) {
        if (k == 4) {
            if (!map.containsKey(query)) {
                map.put(query, new ArrayList<Integer>());
            }
            map.get(query).add(Integer.parseInt(info[4]));
            return;
        }
        
        dfs(k + 1, query + "-", info);
        dfs(k + 1, query + info[k], info);
    }
    
    private int binarySearch(String query, int score) {
        List<Integer> list = map.get(query);
        int st = 0;
        int en = list.size() - 1;
        
        while (st <= en) {
            int mid = (st + en) / 2;
            if (list.get(mid) < score) st = mid + 1;
            else en = mid - 1 ;
        }
        
        return list.size() - st;
    }
}