#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

vector<int> tree[10001];
int depth[10001];
int parent[10001];

void getDepth(int x) {
  for (int child : tree[x]) {
    if (depth[child] > -1) continue;
    depth[child] = depth[x] + 1;
    getDepth(child);
  }
}

int getRoot(int x) {
  if (parent[x] == 0) return x;
  return getRoot(parent[x]);
}

int nca(int a, int b) {
  if (depth[a] != depth[b]) {
    if (depth[a] < depth[b]) swap(a, b);
    int diff = depth[a] - depth[b];
    int p = a;
    while (diff--) p = parent[p];
    a = p;
  }

  if (a == b) return a;
  if (a == parent[b]) return a;
  if (b == parent[a]) return b;

  while (parent[a] != parent[b]) {
    a = parent[a];
    b = parent[b];
  }
  return parent[a];
}

void solve() {
  int t;
  cin >> t;
  while (t--) {
    for (int i = 1; i < 10001; i++) {
      tree[i].clear();
      parent[i] = 0;
      depth[i] = -1;
    }

    int n;
    cin >> n;

    int root;
    int a, b;
    for (int i = 1; i < n; i++) {
      cin >> a >> b;
      tree[a].push_back(b);
      parent[b] = a;
      root = b;
    }
    cin >> a >> b;

    root = getRoot(root);
    depth[root] = 0;
    getDepth(root);
    cout << nca(a, b) << endl;
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