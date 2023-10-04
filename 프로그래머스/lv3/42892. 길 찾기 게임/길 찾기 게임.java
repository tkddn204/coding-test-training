import java.util.*;
import java.util.stream.*;

class Solution {
    
    class Node {
        int x, y, num;
        Node left, right;
        Node(int x, int y, int num) {
            this.x = x;
            this.y = y;
            this.num = num;
        }
    }
    
    Node[] tree;
    List<Integer> pre, post;
    
    void addTree(Node parent, Node child) {
        if (parent.x > child.x) {
            if (parent.left == null) parent.left = child;
            else addTree(parent.left, child);
        } else {
            if (parent.right == null) parent.right = child;
            else addTree(parent.right, child);
        }
    }
    
    private void preorder(Node root) {
        if (root == null) return;
        
        pre.add(root.num);
        preorder(root.left);
        preorder(root.right);
    }
    
    private void postorder(Node root) {
        if (root == null) return;
    
        postorder(root.left);
        postorder(root.right);
        post.add(root.num);
    }
    
    public int[][] solution(int[][] nodeinfo) {
        int[][] answer;
        int n = nodeinfo.length;
        pre = new ArrayList<>();
        post = new ArrayList<>();
        
        tree = new Node[n];
        for (int i = 0; i < n; i++) {
            tree[i] = new Node(nodeinfo[i][0], nodeinfo[i][1], i + 1);
        }
        
        Arrays.sort(tree, (a, b) -> {
            if (a.y == b.y) {
                return Integer.compare(a.x, b.x);
            }
            return Integer.compare(b.y, a.y);
        });
        
        Node root = tree[0];
        for (int i = 1; i < n; i++) {
            addTree(root, tree[i]);
        }
        
        preorder(root);
        postorder(root);
        
        answer = new int[2][];
        answer[0] = pre.stream().mapToInt(Integer::intValue).toArray();
        answer[1] = post.stream().mapToInt(Integer::intValue).toArray();
        
        return answer;
    }
}