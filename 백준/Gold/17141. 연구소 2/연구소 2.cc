#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n, m;
int room[51][51];
vector<pair<int,int>> birus;
int b[11];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int res = 1e9;

int rep() {
  int r[51][51];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      r[i][j] = room[i][j];
    }
  }

  for (int i = 0; i < m; i++) {
    auto [x, y] = birus[b[i]];
    r[x][y] = 2;
  }

  int cnt = 0;
  bool end = false;
  while (true) {
    int tmp[51][51];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        tmp[i][j] = r[i][j];
      }
    }

    for (int x = 0; x < n; x++) {
      for (int y = 0; y < n; y++) {
        if (r[x][y] < 2) continue;

        for (int d = 0; d < 4; d++) {
          int nx = x + dx[d];
          int ny = y + dy[d];
          if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
          if (r[nx][ny]) continue;
          tmp[nx][ny] = 2;
        }
      }
    }

    bool end = true;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (r[i][j] != tmp[i][j]) end = false;
        r[i][j] = tmp[i][j];
      }
    }
    if (end) break;
    

    cnt++;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (r[i][j] == 0) return 1e9;
    }
  }
  return cnt;
}

void go(int c, int k) {
  if (k == m) {
    res = min(res, rep());
    return;
  }


  for (int i = c; i < birus.size(); i++) {
    b[k] = i;
    go(i + 1, k + 1);
  }
}

void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> room[i][j];
      if (room[i][j] == 2) {
        birus.push_back({i, j});
        room[i][j] = 0;
      }
    }
  }

  go(0, 0);

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