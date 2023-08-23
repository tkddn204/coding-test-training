#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int pool[52][52];
bool vst[52][52];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char k; cin >> k;
      pool[i][j] = k - '0';
    }
  }

  int cnt = 0;
  for (int h = 0; h <= 9; h++) {
    
    for (int i = 0; i < n + 2; i++) {
      fill(vst[i], vst[i] + m + 2, 0);
    }

    queue<pair<int,int>> Q;
    Q.push({0, 0});
    vst[0][0] = true;
    while (!Q.empty()) {
      auto [x, y] = Q.front(); Q.pop();

      for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (nx < 0 or nx >= n + 2 or ny < 0 or ny >= m + 2) continue;
        if (vst[nx][ny]) continue;
        if (pool[nx][ny] != pool[x][y]) continue;
        vst[nx][ny] = true;
        Q.push({nx, ny});
      }
    }

    for (int i = 0; i <= n + 1; i++) {
      for (int j = 0; j <= m + 1; j++) {
        if (pool[i][j] == h) {
          if (!vst[i][j]) cnt++;
          pool[i][j]++;
        }
      }
    }
  }
  cout << cnt;

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