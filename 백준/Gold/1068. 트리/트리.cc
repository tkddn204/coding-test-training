#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n, k;
vector<int> tree[51];
int cnt;

bool dfs(int root) {  
  if (root == k) return true;

  if (tree[root].empty()) {
    cnt++;
    return false;
  }

  for (int child : tree[root]) {
    bool isFind = dfs(child);
    if (isFind and tree[root].size() == 1) {
      cnt++;
    }
  }
  return false;
}

void solve() {
  cin >> n;

  int root = -1;
  for (int i = 0; i < n; i++) {
    int e;
    cin >> e;
    if (e == -1) root = i;
    else tree[e].push_back(i);
  }
  cin >> k;
  
  if (k != root) {
    dfs(root);
  }

  cout << cnt;
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