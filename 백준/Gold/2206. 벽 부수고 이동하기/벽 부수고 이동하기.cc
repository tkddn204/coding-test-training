#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int mp[1001][1001];
int vst[11][1001][1001];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void solve() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      mp[i][j] = s[j] == '1';
    }
  }

  queue<tuple<int,int,int>> Q;
  Q.push({0, 0, 0});
  vst[0][0][0] = 1;
  while (!Q.empty()) {
    auto [b, x, y] = Q.front(); Q.pop();

    for (int d = 0; d < 4; d++) {
      int nb = b + 1;
      int nx = x + dx[d];
      int ny = y + dy[d];

      if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
      if (vst[b][nx][ny]) continue;
      if (mp[nx][ny]) {
        if (b == 1) continue;
        if (vst[nb][nx][ny]) continue;
        vst[nb][nx][ny] = vst[b][x][y] + 1;
        Q.push({nb, nx, ny});
      } else {
        vst[b][nx][ny] = vst[b][x][y] + 1;
        Q.push({b, nx, ny});
      }
    }
  }

  int res = 1e9;
  for (int b = 0; b <= 1; b++) {
    int dis = vst[b][n - 1][m - 1];
    if (dis == 0) continue;
    res = min(res, dis);
  }
  if (res == 1e9) cout << -1;
  else cout << res;
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