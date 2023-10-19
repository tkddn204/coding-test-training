#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n, m, h;
int ladder[31][11];
int res = -1;

bool go() {
  for (int j = 1; j <= n; j++) {
    int pos = j;
    for (int i = 1; i <= h; i++) {
      if (ladder[i][pos] > 0) {
        pos = ladder[i][pos];
      }
    }
    if (pos != j) return false;
  }
  return true;
}

void bt(int nxt, int k, int limit) {
  if (k == limit) {
    if (go()) res = max(res, k);
    return;
  }

  for (int i = nxt; i <= h; i++) {
    for (int j = 1; j < n; j++) {
      if (ladder[i][j] || ladder[i][j + 1]) continue;
      ladder[i][j] = j + 1;
      ladder[i][j + 1] = j;
      bt(i, k + 1, limit);
      ladder[i][j] = 0;
      ladder[i][j + 1] = 0;
    }
  }
}

void solve() {
  cin >> n >> m >> h;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    ladder[a][b] = b + 1;
    ladder[a][b + 1] = b;
  }
  // for (int i = 1; i <= h; i++) {
  //   for (int j = 1; j <= n; j++) {
  //     cout << ladder[i][j] << ' ';
  //   }
  //   cout << endl;
  // }
  if (m == 0) {
    cout << 0;
    return;
  }

  for (int i = 0; i < 4; i++) {
    bt(0, 0, i);
    if (res > -1) {
      cout << res;
      return;
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