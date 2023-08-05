#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int r, c;
string cave[101];
int vst[101][101];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void rearrange() {
  for (int i = 0; i < r ; i++) {
    fill(vst[i], vst[i] + c, 0);
  }

  // 내리지 않아도 되는 곳 찾기  
  queue<pair<int, int>> Q;
  for (int j = 0; j < c; j++) {
    if (cave[r - 1][j] == 'x') {
      Q.push({r - 1, j});
      vst[r - 1][j] = 1;
    }
  }
  while (!Q.empty()) {
    auto [x, y] = Q.front(); Q.pop();

    for (int d = 0; d < 4; d++) {
      int nx = x + dx[d];
      int ny = y + dy[d];
      if (nx < 0 or nx >= r or ny < 0 or ny >= c) continue;
      if (vst[nx][ny] != 0 or cave[nx][ny] == '.') continue;
      Q.push({nx, ny});
      vst[nx][ny] = 1;
    }
  }
  
  // 얼마나 이동할 수 있는지 검사
  int sft = r;
  for (int i = r - 1; i >= 0; i--) {
    for (int j = 0; j < c; j++) {
      if (vst[i][j] or cave[i][j] == '.') continue;

      sft = min(sft, r - i - 1);
      for (int k = i + 1; k < r; k++) {
        if (vst[k][j] and cave[k][j] == 'x') {
          sft = min(sft, k - i - 1);
        }
      }
    }
  }

  // 내리기
  for (int i = r - 1; i >= 0; i--) {
    for (int j = 0; j < c; j++) {
      if (vst[i][j] or cave[i][j] == '.') continue;
      cave[i][j] = '.';
      cave[i + sft][j] = 'x';
    }
  }
}

void go(int col, int dr) {
  // 던지기
  if (dr == 0) { // 왼쪽 -> 오른쪽
    for (int j = 0; j < c; j++) {
      if (cave[col][j] == 'x') {
        cave[col][j] = '.';
        return;
      }
    }
  } else { // 오른쪽 -> 왼쪽
    for (int j = c - 1; j >= 0; j--) {
      if (cave[col][j] == 'x') {
        cave[col][j] = '.';
        return;
      }
    }
  }
}

void solve() {
  cin >> r >> c;
  for (int i = 0; i < r; i++) cin >> cave[i];
  
  int n, turn = 0;
  cin >> n;
  while (n--) {
    int h;
    cin >> h;
    go(r - h, turn++ % 2);
    rearrange();
  }

  for (int i = 0; i < r; i++) {
    cout << cave[i] << endl;
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