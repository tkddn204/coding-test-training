import java.util.*;
import java.util.stream.*;

class Solution {
    public int[] solution(int[] arr, int[] delete_list) {
        return Arrays.stream(arr).filter(val -> {
            for (int del : delete_list) {
                if (val == del) return false;
            }
            return true;
        }).toArray();
    }
}