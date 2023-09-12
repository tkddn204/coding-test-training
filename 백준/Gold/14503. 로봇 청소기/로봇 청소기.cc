#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define X first
#define Y second

int n, m;
int room[51][51];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void solve() {
  cin >> n >> m;
  int r, c, d;
  cin >> r >> c >> d;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> room[i][j];
    }
  }

  while (true) {
    room[r][c] = -1;

    bool isClean = true;
    for (int i = 0; i < 4; i++) {
      int nx = r + dx[i];
      int ny = c + dy[i];
      if (0 > nx || nx >= n || 0 > ny || ny >= m) continue;
      if (room[nx][ny] == 1) continue;
      if (room[nx][ny] == 0) {
        isClean = false;
        break;
      }
    }

    if (isClean) {
      int b = (d + 2) % 4;
      int nx = r + dx[b];
      int ny = c + dy[b];
      if (0 > nx || nx >= n || 0 > ny || ny >= m) break;
      if (room[nx][ny] == 1) break;
      r = nx, c = ny;
    } else {
      d = d > 0 ? d - 1 : 3;
      int nx = r + dx[d];
      int ny = c + dy[d];
      if (0 > nx || nx >= n || 0 > ny || ny >= m) continue;
      if (room[nx][ny] == 0) r = nx, c = ny;
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cnt += room[i][j] == -1;
    }
  }
  cout << cnt;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  solve();
  return 0;
}