#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
  while (true) {
    int n, k;
    cin >> n >> k;
    if (n + k == 0) break;
    
    vector<int> tree;
    map<int, int> parent;
    
    int root;
    cin >> root;
    int pre = root;
    
    int group = -1;
    tree.push_back(root);
    parent[root] = -1;
    for (int i = 1; i < n; i++) {
      int e;
      cin >> e;
      tree.push_back(e);
      
      if (abs(e - pre) > 1) group++;
      parent[e] = tree[group];
      
      pre = e;
    }

    int res = 0;
    if (k != root) {
      for (int e : tree) {
        if (parent[e] == parent[k]) continue;
        if (parent[parent[e]] == parent[parent[k]]) {
          res++;
        }
      }
    }
    cout << res << endl;
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#endif
  solve();
  return 0;
}