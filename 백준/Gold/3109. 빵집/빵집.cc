#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int r, c;
string s[10001];
bool vst[10001][501];
int dx[] = {-1, 0, 1};
int dy[] = {1, 1, 1};

bool dfs(int x, int y) {
  vst[x][y] = true;

  if (y == c - 1) return true;

  for (int d = 0; d < 3; d++) {
    int nx = x + dx[d];
    int ny = y + dy[d];

    if (nx < 0 or nx >= r or ny < 0 or ny >= c) continue;
    if (s[nx][ny] == 'x' or vst[nx][ny]) continue;
    if (dfs(nx, ny)) return true;
  }
  return false;
}

void solve() {
  cin >> r >> c;
  for (int i = 0; i < r; i++) cin >> s[i];

  int cnt = 0;
  for (int i = 0; i < r; i++) {
    if (dfs(i, 0)) cnt++;
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