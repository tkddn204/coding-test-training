import java.io.*;
import java.util.*;

class Solution {
    public int[] solution(String[] id_list, String[] report, int k) {
        int[] answer = new int[id_list.length];
        
        Map<String, HashSet<String>> idMap = new HashMap<>();
        Map<String, Integer> reportMap = new HashMap<>();
        HashSet<String> reportSet = new HashSet<>(Arrays.asList(report));
        
        for (String e : reportSet) {
            String[] splited = e.split(" ");
            
            idMap.putIfAbsent(splited[0], new HashSet<String>());
            idMap.get(splited[0]).add(splited[1]);
            reportMap.put(splited[1], reportMap.getOrDefault(splited[1], 0) + 1);
        }
        
        for (int i = 0; i < id_list.length; i++) {
            String id = id_list[i];
            if (!idMap.containsKey(id)) continue;
            int cnt = 0;
            for (String reportedId : idMap.get(id)) {
                if (reportMap.get(reportedId) >= k) cnt++;
            }
            System.out.println();
            answer[i] = cnt;
        }
        
        return answer;
    }
}