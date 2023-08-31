#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int room[9][9];
int chk[9][9];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool wall[9*9];

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> room[i][j];
    }
  }

  int maxSafe = 0;
  fill(wall + 3, wall + (n*m), true);
  do {
    queue<pair<int, int>> Q;

    bool isValid = true;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        chk[i][j] = room[i][j];
        if (!wall[i * m + j]) {
          if (chk[i][j] > 0) {
            isValid = false;
            break;
          }
          chk[i][j] = 1;
        }
        if (chk[i][j] == 2) Q.push({i, j});
      }
      if (!isValid) break;
    }

    if (!isValid) continue;

    while (!Q.empty()) {
      int x, y;
      tie(x, y) = Q.front(); Q.pop();
      for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (chk[nx][ny] > 0) continue;
        chk[nx][ny] = 2;
        Q.push({nx, ny});
      }
    }

    int safe = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) { 
        safe += chk[i][j] == 0;
      }
    }
    maxSafe = max(maxSafe, safe);
  } while(next_permutation(wall, wall + (n*m)));
  cout << maxSafe;
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