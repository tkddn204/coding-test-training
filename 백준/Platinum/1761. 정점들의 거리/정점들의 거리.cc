#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n;
map<int,int> tree[40001];
int parent[40001][20];
int dist[40001][20];
int depth[40001];

void init(int root) {
  for (auto [nxt, d] : tree[root]) {
    if (depth[nxt] > -1) continue;
    parent[nxt][0] = root;
    dist[nxt][0] = d;
    depth[nxt] = depth[root] + 1;
    init(nxt);
  }
}

void setParent() {
  for (int j = 1; j < 20; j++) {
    for (int i = 1; i <= n; i++) {
      if (parent[i][j - 1] == 0) continue;
      int anc = parent[i][j - 1];
      parent[i][j] = parent[anc][j - 1];
      dist[i][j] = dist[i][j - 1] + dist[anc][j - 1];
    }
  }
}

int go(int a, int b) {
  int len = 0;

  if (depth[a] != depth[b]) {
    if (depth[a] < depth[b]) swap(a, b);

    int diff = depth[a] - depth[b];
    for (int i = 0; diff > 0; i++) {
      if (diff % 2) {
        len += dist[a][i];
        a = parent[a][i];
      }
      diff = diff >> 1;
    }
  }

  if (a != b) {
    for (int k = 19; k >= 0; k--) {
      if (parent[a][k] and parent[a][k] != parent[b][k]) {
        len += dist[a][k];
        len += dist[b][k];
        a = parent[a][k];
        b = parent[b][k];
      }
    }
    len += dist[a][0];
    len += dist[b][0];
  }


  return len;
}

void solve() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b, d;
    cin >> a >> b >> d;
    tree[a][b] = d;
    tree[b][a] = d;
  }

  fill(depth, depth + n + 1, -1);
  depth[1] = 0;

  init(1);
  setParent();

  int m;
  cin >> m;
  while (m--) {
    int a, b;
    cin >> a >> b;
    cout << go(a, b) << endl;
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