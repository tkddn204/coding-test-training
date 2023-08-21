#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int mp[201][201];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
queue<pair<int,int>> birus[1001];

void solve() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> mp[i][j];
      if (mp[i][j] != 0) {
        birus[mp[i][j]].push({i, j});
      }
    }
  }
  int s, sx, sy;
  cin >> s >> sx >> sy;
  sx--, sy--;

  while (s--) {
    for (int i = 1; i <= k; i++) {
      int size = birus[i].size();
      while (size--) {
        auto [x, y] = birus[i].front(); birus[i].pop();
        for (int d = 0; d < 4; d++) {
          int nx = x + dx[d];
          int ny = y + dy[d];

          if (nx < 0 or nx >= n or ny < 0 or ny >= n) continue;
          if (mp[nx][ny] != 0) continue;
          mp[nx][ny] = i;
          birus[i].push({nx, ny});
        }
      }
    }
  }

  cout << mp[sx][sy];
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