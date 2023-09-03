#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int mp[1001][1001];
int vst[2][11][1001][1001];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void solve() {
  int n, m, k;
  cin >> n >> m >> k;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      mp[i][j] = s[j] == '1';
    }
  }

  queue<tuple<int,int,int,int>> Q;
  Q.push({0, 0, 0, 0});
  vst[0][0][0][0] = 1;
  while (!Q.empty()) {
    auto [day, b, x, y] = Q.front(); Q.pop();

    for (int d = 0; d < 4; d++) {
      int nday = !day;
      int nb = b + 1;
      int nx = x + dx[d];
      int ny = y + dy[d];

      if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
      if (mp[nx][ny]) {
        if (day) {
          if (!vst[nday][b][x][y]) {
            vst[nday][b][x][y] = vst[day][b][x][y] + 1;
            Q.push({nday, b, x, y});
          }
          continue;
        }
        if (b == k) continue;
        if (vst[nday][nb][nx][ny]) continue;
        vst[nday][nb][nx][ny] = vst[day][b][x][y] + 1;
        Q.push({nday, nb, nx, ny});
      } else {
        if (vst[nday][b][nx][ny]) continue;
        vst[nday][b][nx][ny] = vst[day][b][x][y] + 1;
        Q.push({nday, b, nx, ny});
      }
    }
  }
  
  // for (int day = 0; day < 2; day++) {
  //   for (int b = 0; b <= k; b++) {
  //     for (int i = 0; i < n; i++) {
  //       for (int j = 0; j < m; j++) {
  //         cout << vst[day][b][i][j];
  //       }
  //       cout << endl;
  //     }
  //     cout << "--------" << endl;
  //   }
  // }

  int res = 1e9;
  for (int day = 0; day < 2; day++) {
    for (int b = 0; b <= k; b++) {
      int dis = vst[day][b][n - 1][m - 1];
      if (dis == 0) continue;
      res = min(res, dis);
    }
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