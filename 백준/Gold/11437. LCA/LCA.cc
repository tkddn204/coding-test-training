#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n;
vector<int> tree[50001];
int parent[50001];
int depth[50001];

void init(int root) {
  for (int nxt : tree[root]) {
    if (depth[nxt] > -1) continue;
    parent[nxt] = root;
    depth[nxt] = depth[root] + 1;
    init(nxt);
  }
}

int LCA(int a, int b) {
  while (depth[a] != depth[b]) {
    if (depth[a] > depth[b]) a = parent[a];
    if (depth[a] < depth[b]) b = parent[b];
  }

  while (a != b) {
    a = parent[a];
    b = parent[b];
  }

  return a;
}

void solve() {
  cin >> n;

  fill(depth, depth + n + 1, -1);
  depth[1] = 0;

  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }

  init(1);

  int m;
  cin >> m;
  while (m--) {
    int a, b;
    cin >> a >> b;
    cout << LCA(a, b) << endl;
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