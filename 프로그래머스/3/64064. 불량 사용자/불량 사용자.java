import java.util.*;

class Solution {
    
    boolean check(String p, String w) {
        if (p.length() != w.length()) return false;
        
        for (int i = 0; i < w.length(); i++) {
            if (p.charAt(i) != '*' && p.charAt(i) != w.charAt(i)) {
                return false;
            }
        }
        
        return true;
    }
    
    String[] userId, bannedId;
    Set<HashSet<String>> res = new HashSet<>();
    
    void go(int k, HashSet<String> set) {
        if (k == bannedId.length) {
            res.add(set);
            return;
        }
        
        for (int i = 0; i < userId.length; i++) {
            if (set.contains(userId[i])) continue;
            
            if (check(bannedId[k], userId[i])) {
                set.add(userId[i]);
                go(k + 1, new HashSet<>(set));
                set.remove(userId[i]);
            }
        }
    }
    
    public int solution(String[] user_id, String[] banned_id) {
        userId = user_id;
        bannedId = banned_id;
        
        go(0, new HashSet<>());
        
        return res.size();
    }
}