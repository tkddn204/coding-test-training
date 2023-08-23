#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

const int MAX = 18;
int n;
vector<int> tree[100001];
int parent[100001][MAX];
int depth[100001];

void init(int root) {
  for (int nxt : tree[root]) {
    if (depth[nxt] > -1) continue;
    parent[nxt][0] = root;
    depth[nxt] = depth[root] + 1;
    init(nxt);
  }
}

int LCA(int a, int b) {
  if (depth[a] < depth[b]) swap(a, b);

  // 깊이 차이 없애기
  int diff = depth[a] - depth[b];
  for (int p = 0; diff; p++) {
    if (diff % 2 == 1) a = parent[a][p];
    diff /= 2;
  }

  // 올리기
  if (a != b) {
    for (int p = MAX - 1; p >= 0; p--) {
      if (parent[a][p] == -1) continue;
      if (parent[a][p] == parent[b][p]) continue;
      a = parent[a][p];
      b = parent[b][p];
    }
    a = parent[a][0];
  }

  return a;
}

void solve() {
  cin >> n;
  
  fill(depth, depth + n + 1, -1);
  depth[1] = 0;
  for (int i = 0; i <= n; i++) {
    fill(parent[i], parent[i] + MAX, -1);
  }

  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }

  init(1);
  for (int p = 0; p < MAX; p++) {
    for (int c = 1; c <= n; c++) {
      if (parent[c][p] != -1)
      parent[c][p + 1] = parent[parent[c][p]][p];
    }
  }

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