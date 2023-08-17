#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int r, c, n;
string pan[201];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int bomb[201][201];
int tim = 1;

void fillBomb() {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (pan[i][j] == 'O') continue;
      pan[i][j] = 'O';
      bomb[i][j] = tim+3;
    }
  }
}

void explode() {
  for (int x = 0; x < r; x++) {
    for (int y = 0; y < c; y++) {
      if (bomb[x][y] != tim) continue;

      pan[x][y] = '.';
      for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx < 0 or nx >= r or ny < 0 or ny >= c) continue;
        pan[nx][ny] = '.';
        bomb[x][y] = 0;
      }
    }
  }
}

void solve() {
  cin >> r >> c >> n;
  for (int i = 0; i < r; i++) {
    cin >> pan[i];
    for (int j = 0; j < c; j++) {
      if (pan[i][j] == 'O') bomb[i][j] = 3;
    }
  }

  while (tim <= n) {
    if (tim % 2 == 0) fillBomb();
    else explode();
    tim++;
  }
  for (int i = 0; i < r; i++)
    cout << pan[i] << endl;
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