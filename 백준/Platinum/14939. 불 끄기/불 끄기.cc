#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int light[101][101];
int tmp[101][101];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool allOff() {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (tmp[i][j]) return false;
    }
  }
  return true;
}

void toggle(int x, int y) {
  tmp[x][y] = !tmp[x][y];
  for (int d = 0; d < 4; d++) {
    int nx = x + dx[d];
    int ny = y + dy[d];

    if (nx < 0 or nx >= 10 or ny < 0 or ny >= 10) continue;
    tmp[nx][ny] = !tmp[nx][ny];
  }
}

void solve() {
  for (int i = 0; i < 10; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < 10; j++) {
      if (s[j] == 'O') light[i][j] = 1;
    }
  }

  int res = INT_MAX;
  for (int t = 0; t < (1 << 10); t++) {
    int cnt = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
          tmp[i][j] = light[i][j];
      }
    }

    for (int b = 0; b < 10; b++) {
      if (t & (1 << b)) {
        cnt++;
        toggle(0, b);
      }
    }
    for (int i = 1; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        if (tmp[i - 1][j]) {
          toggle(i, j);
          cnt++;
        }
      }
    }

    if (allOff()) res = min(res, cnt);
  }
  if (res == INT_MAX) cout << -1;
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