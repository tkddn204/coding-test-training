#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n, m, k;
string gym[1001];
int vst[1001][1001];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void solve() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> gym[i];
    fill(vst[i], vst[i] + m, -1);
  }
  int sx, sy, ex, ey;
  cin >> sx >> sy >> ex >> ey;
  sx--, sy--, ex--, ey--;

  queue<pair<int,int>> Q;
  Q.push({sx, sy});
  vst[sx][sy] = 0;
  while (!Q.empty()) {
    auto [x, y] = Q.front(); Q.pop();
    
    for (int d = 0; d < 4; d++) {
      for (int nk = 1; nk <= k; nk++) {
        int nx = x + dx[d]*nk;
        int ny = y + dy[d]*nk;

        if (nx < 0 or nx >= n or ny < 0 or ny >= m) break;
        if (gym[nx][ny] == '#') break;
        if (vst[nx][ny] == -1) {
          vst[nx][ny] = vst[x][y] + 1;
          Q.push({nx, ny});
        } else if (vst[nx][ny] <= vst[x][y]) break;
      }
    }
  }
  cout << vst[ex][ey];
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