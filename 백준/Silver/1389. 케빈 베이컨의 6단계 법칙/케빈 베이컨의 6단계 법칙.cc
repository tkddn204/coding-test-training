#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int dist[101][101];

void solve() {
  int n, m;
  cin >> n >> m;

  
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dist[i][j] = 1e9;
    }
  }

  while (m--) {
    int a, b;
    cin >> a >> b;
    dist[a][b] = dist[b][a] = 1;
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  int minval = 1e9;
  int res = 0;
  for (int i = 1; i <= n; i++) {
    int val = 0;
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      val += dist[i][j];
    }
    if (val < minval) {
      minval = min(minval, val);
      res = i;
    }
  }
  cout << res;
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