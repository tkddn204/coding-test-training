#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int pan[8][8];
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

bool chk() {
  for (int i = 0; i < 6; i++) {
    for (int j = 1; j < 7; j++) {
      if (pan[i][j] != 1) return false;
    }
  }
  return true;
}

bool isgo(int sx, int sy, int ex, int ey) {
  for (int d = 0; d < 8; d++) {
    int nx = sx + dx[d];
    int ny = sy + dy[d];
    if (nx < 0 || nx >= 6 || ny < 1 || ny >= 7) continue;
    if (nx == ex && ny == ey) {
      return true;
    }
  }
  return false;
}

void solve() {
  char a, b;
  int sx, sy, ex, ey;
  bool valid = true;
  int px, py;
  for (int i = 0; i < 36; i++) {
    cin >> a >> b;
    pan[a - 'A'][b - '0']++;
    if (i == 0) {
      sx = a - 'A'; sy = b - '0';
    } else {
      if (i == 35) {
        ex = a - 'A'; ey = b - '0';
      }
      if (!isgo(px, py, a - 'A', b - '0')) {
        valid = false;
      }
    }
    px = a - 'A'; py = b - '0';
  }

  if (!valid || !chk() || !isgo(sx, sy, ex, ey)) {
    cout << "Invalid";
  } else {
    cout << "Valid";
  }
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