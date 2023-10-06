import java.util.*;
import java.util.stream.*;

class Solution {
    
    class Student implements Comparable<Student> {
        int rank;
        boolean attend;
        int idx;
        
        Student(int rank, boolean attend, int idx) {
            this.rank = rank;
            this.attend = attend;
            this.idx = idx;
        }
        
        public int compareTo(Student s) {
            if (this.attend == s.attend) {
                return Integer.compare(this.rank, s.rank);
            }
            return Boolean.compare(s.attend, this.attend);
        }
    }
    
    public int solution(int[] rank, boolean[] attendance) {
        int answer = 0;
        int n = rank.length;
        List<Student> students = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            students.add(new Student(rank[i], attendance[i], i));
        }
        Collections.sort(students);
        
        int k = 10000;
        for (Student st: students.stream().limit(3).collect(Collectors.toList())) {
            answer += st.idx * k;
            k /= 100;
        }
        
        return answer;
    }
}