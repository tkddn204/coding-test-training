#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n;
int pan[11][11];
bool leftDiag[22];
bool rightDiag[22];
int maxCnt[2];
int color;

void go(int x, int y, int cnt) {
  if (y >= n) {
    x++;
    y = (y % 2 == 0);
  }
  if (x >= n) {
    maxCnt[color] = max(maxCnt[color], cnt);
    return;
  }

  bool chked = leftDiag[x + y] or rightDiag[n - 1 + x - y];

  if (pan[x][y] and !chked) {
    leftDiag[x + y] = true;
    rightDiag[n - 1 + x - y] = true;
    go(x, y + 2, cnt + 1);
    leftDiag[x + y] = false;
    rightDiag[n - 1 + x - y] = false;
  }
  go(x, y + 2, cnt);
}

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> pan[i][j];
    }
  }

  color = 0;go(0, 0, 0);
  color = 1;go(0, 1, 0);
  cout << maxCnt[0] + maxCnt[1];
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