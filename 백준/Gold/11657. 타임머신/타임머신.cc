#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

ll dist[501];
vector<pair<int,int>> bus[501];

void solve() {
  int n, m;
  cin >> n >> m;

  fill(dist, dist + 501, INT_MAX);
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    bus[a].push_back({b, c});
  }

  dist[1] = 0;
  bool iscycle = false;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (auto [k, c]: bus[j]) {
        if (dist[j] != INT_MAX && dist[k] > dist[j] + c) {
          dist[k] = dist[j] + c;
          if (i == n) {
            iscycle = true;
            break;
          }
        }
      }
      if (iscycle) break;
    }
  }
  if (iscycle) {
    cout << -1 << endl;
    return;
  }
  
  for (int i = 2; i <= n; i++) {
    if (dist[i] == INT_MAX) cout << -1 << endl;
    else cout << dist[i] << endl;
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