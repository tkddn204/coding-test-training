#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n, m;
int wall[51][51];
int roomcnt;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

int bfs() {
  bool vst[51][51];
  for (int i = 0; i < m; i++) {
    fill(vst[i], vst[i] + n, false);
  }
  int res = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (vst[i][j]) continue;
      queue<pair<int,int>> Q;
      Q.push({i, j});
      vst[i][j] = true;
      roomcnt++;
      int cnt = 0;
      while (!Q.empty()) {
        auto [x, y] = Q.front(); Q.pop();
        cnt++;
        for (int d = 0; d < 4; d++) {
          int nx = x + dx[d];
          int ny = y + dy[d];
          if (nx < 0 or nx >= m or ny < 0 or ny >= n) continue;
          if (wall[x][y] & (1 << d)) continue;
          if (vst[nx][ny]) continue;
          Q.push({nx, ny});
          vst[nx][ny] = true;
        }
      }
      res = max(res, cnt);
    }
  }
  return res;
}

void solve() {
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> wall[i][j];
    }
  }

  int mx = bfs();
  cout << roomcnt << endl;
  cout << mx << endl;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      for (int d = 0; d < 4; d++) {
        int b = (1 << d);
        if (wall[i][j] & b) {
          wall[i][j] ^= b;
          mx = max(mx, bfs());
          wall[i][j] ^= b;
        }
      }
    }
  }
  cout << mx;
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