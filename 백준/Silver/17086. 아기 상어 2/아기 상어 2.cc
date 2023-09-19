#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int mp[51][51];
int vst[51][51];
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mp[i][j];
    }
  }

  int res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mp[i][j]) continue;

      for (int k = 0; k < n; k++)
        fill(vst[k], vst[k] + m, -1);
      
      queue<pair<int,int>> Q;
      Q.push({i, j});
      vst[i][j] = 0;
      while (!Q.empty()) {
        auto [x, y] = Q.front(); Q.pop();
        
        if (mp[x][y] == 1) {
          res = max(res, vst[x][y]);
          break;
        }

        for (int d = 0; d < 8; d++) {
          int nx = x + dx[d];
          int ny = y + dy[d];

          if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
          if (vst[nx][ny] > -1) continue;
          Q.push({nx, ny});
          vst[nx][ny] = vst[x][y] + 1;
        }
      }
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