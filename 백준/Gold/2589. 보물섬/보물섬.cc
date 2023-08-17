#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

string mp[51];
int vst[51][51];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int maxTime = 0;

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> mp[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mp[i][j] == 'W') continue;

      for (int k = 0; k < n; k++)
        fill(vst[k], vst[k] + m, -1);

      queue<pair<int,int>> Q;
      Q.push({i, j});
      vst[i][j] = 0;
      while (!Q.empty()) {
        auto [x, y] = Q.front(); Q.pop();

        for (int d = 0; d < 4; d++) {
          int nx = x + dx[d];
          int ny = y + dy[d];
          if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
          if (vst[nx][ny] > -1 or mp[nx][ny] == 'W') continue;
          Q.push({nx, ny});
          vst[nx][ny] = vst[x][y] + 1;
          maxTime = max(maxTime, vst[nx][ny]);
        }
      }
    }
  }
  cout << maxTime;
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