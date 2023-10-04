import java.util.*;
import java.util.stream.*;

class Solution {
    
    class Pair {
        int x, num;
        Pair(int x, int num) {
            this.x = x;
            this.num = num;
        }
    }
    
    int[] tree;
    List<Integer> pre, post;
    Map<Integer, ArrayList<Pair>> map;
    
    void addTree(int idx, int level, Pair node, int st, int en) {
        tree[idx] = node.num;
        
        level--;
        while (level > 0 && map.get(level).isEmpty()) level--;
        for (Pair nxt : map.get(level)) {
            if (st <= nxt.x && nxt.x < node.x) {
                addTree(idx * 2, level, nxt, st, node.x);
            } else if (node.x < nxt.x && nxt.x <= en) {
                addTree(idx * 2 + 1, level, nxt, node.x, en);
            }
        }
        
    }
    
    private void preorder(int root) {
        if (root >= tree.length) return;
        if (tree[root] == 0) return;
        
        pre.add(tree[root]);
        preorder(root * 2);
        preorder(root * 2 + 1);
    }
    
    private void postorder(int root) {
        if (root >= tree.length) return;
        if (tree[root] == 0) return;
    
        postorder(root * 2);
        postorder(root * 2 + 1);
        post.add(tree[root]);
    }
    
    public int[][] solution(int[][] nodeinfo) {
        int[][] answer;
        int n = nodeinfo.length;
        pre = new ArrayList<>();
        post = new ArrayList<>();
        
        tree = new int[100001];
        map = new HashMap<>();
        for (int i = 0; i < 100001; i++) {
            map.put(i, new ArrayList<>());
        }
        
        for (int i = 0; i < n; i++) {
            nodeinfo[i] = new int[]{nodeinfo[i][0], nodeinfo[i][1], i + 1};
            map.get(nodeinfo[i][1]).add(new Pair(nodeinfo[i][0], nodeinfo[i][2]));
        }
        
        Arrays.sort(nodeinfo, (a, b) -> {
            if (a[1] == b[1]) {
                return Integer.compare(a[0], b[0]);
            }
            return Integer.compare(b[1], a[1]);
        });
        
        addTree(1, nodeinfo[0][1], map.get(nodeinfo[0][1]).get(0), 0, nodeinfo[0][2] * 2);
        
        preorder(1);
        postorder(1);
        
        answer = new int[2][];
        answer[0] = pre.stream().mapToInt(Integer::intValue).toArray();
        answer[1] = post.stream().mapToInt(Integer::intValue).toArray();
        
        return answer;
    }
}