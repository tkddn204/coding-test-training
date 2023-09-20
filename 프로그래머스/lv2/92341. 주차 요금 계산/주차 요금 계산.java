import java.io.*;
import java.util.*;

class Solution {
    
    private int getTime(String time) {
        String[] splited = time.split(":");
        int hour = Integer.parseInt(splited[0]);
        int min = Integer.parseInt(splited[1]);
        return hour * 60 + min;
    }
    
    public int[] solution(int[] fees, String[] records) {
        int[] car = new int[10001];
        Arrays.fill(car, -1);
        int[] time = new int[10001];
        
        for (String r : records) {
            String[] splited = r.split(" ");
            int t = getTime(splited[0]);
            int carnum = Integer.parseInt(splited[1]);
            String oper = splited[2];
            
            if (oper.equals("IN")) {
                car[carnum] = t;
            } else {
                if (car[carnum] == -1) continue;
                time[carnum] += t - car[carnum];
                car[carnum] = -1;
            }
        }
        
        
        int last = getTime("23:59");
        for (int i = 0; i < 10001; i++) {
            if (car[i] == -1) continue;
            time[i] += last - car[i];
        }
        
        ArrayList<Integer> res = new ArrayList<>();
        for (int i = 0; i < 10001; i++) {
            if (time[i] == 0) continue;
            
            if (fees[0] >= time[i]) {
                res.add(fees[1]);
            } else {
                double overtime = time[i] - fees[0];
                res.add(fees[1] + (int)(Math.ceil((double)overtime / fees[2]) * fees[3]));
            }
        }
        
        int[] answer = new int[res.size()];
        for (int i = 0; i < res.size(); i++) {
            answer[i] = res.get(i);
        }
        
        return answer;
    }
}