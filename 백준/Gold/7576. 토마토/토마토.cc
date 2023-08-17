#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define x first
#define y second

int vst[1002][1002];
int box[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void solve() {
  queue<pair<int, int>> q;
  int n, m;
  cin >> m >> n;
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> box[i][j];
      if (box[i][j] == 1) {
        q.push({i, j});
      } else if (box[i][j] == 0) {
        vst[i][j] = -1;
      }
    }
  }

  while (!q.empty()) {
    pair<int, int> cur = q.front(); q.pop();

    for (int k = 0 ; k < 4; k++) {
      int nx = cur.x + dx[k];
      int ny = cur.y + dy[k];
      
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (vst[nx][ny] >= 0 || box[nx][ny] == -1) continue;
      vst[nx][ny] = vst[cur.x][cur.y] + 1;
      q.push({nx, ny});
    }
  }

  int mday = 0;
  bool notRipe = false;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (vst[i][j] == -1) notRipe = true;
      else mday = max(mday, vst[i][j]);
    }
  }
  if (notRipe) cout << -1;
  else cout << mday;
  
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