import java.io.*;
import java.util.*;

class Solution {
    
    private int getTime(String time) {
        String[] splited = time.split(":");
        int H = Integer.parseInt(splited[0]);
        int M = Integer.parseInt(splited[0]);
        return H * 60 + M;
    }
    
    public int[] solution(int[] fees, String[] records) {
        int[] answer = {};
        int[] sum = new int[10001];
        
        Map<Integer, Integer> car = new TreeMap<>();
        
        for (String r : records) {
            String[] splited = r.split(" ");
            int t = getTime(splited[0]);
            int carnum = Integer.parseInt(splited[1]);
            String oper = splited[2];
            
            if (oper.equals("IN")) {
                car.put(carnum, t);
            } else {
                int time = t - car.get(carnum);
                if (fees[0] >= time) sum[carnum] += fees[1];
                else {
                    int overtime = time - fees[0];
                    System.out.println(time + " " + fees[0]);
                    sum[carnum] += fees[1] +
                        overtime * (int)(Math.ceil((double)time / (double)10) * fees[3] / fees[2]);
                }
            }    
        }
        
        int size = car.keySet().size();
        answer = new int[size];
        int idx = 0;
        for (int num : car.keySet()) {
           answer[idx++] = sum[num];
        }
        
        return answer;
    }
}