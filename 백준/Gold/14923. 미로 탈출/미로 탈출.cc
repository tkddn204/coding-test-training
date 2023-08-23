#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int arr[1001][1001];
int vst[1001][1001][2];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void solve() {
  int n, m;
  cin >> n >> m;
  int hx, hy, ex, ey;
  cin >> hx >> hy >> ex >> ey;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> arr[i][j];
      vst[i][j][0] = vst[i][j][1] = -1;
    }
  }
  
  queue<tuple<int,int,int>> Q;
  Q.push({hx, hy, 0});
  vst[hx][hy][0] = vst[hx][hy][1] = 0;
  while (!Q.empty()) {
    auto [x, y, ch] = Q.front(); Q.pop();
    
    if (x == ex and y == ey) break;

    for (int d = 0; d < 4; d++) {
      int nx = x + dx[d];
      int ny = y + dy[d];


      if (nx <= 0 or nx >= n + 1 or ny <= 0 or ny >= m + 1) continue;
      if (vst[nx][ny][ch] > -1) continue;
      if (arr[nx][ny] == 1 and ch == 0) {
        vst[nx][ny][1] = vst[x][y][0] + 1;
        Q.push({nx, ny, 1});
      }
      if (arr[nx][ny] == 0) {
        vst[nx][ny][ch] = vst[x][y][ch] + 1;
        Q.push({nx, ny, ch});
      }
    }
  }

  cout << max(vst[ex][ey][0], vst[ex][ey][1]);
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