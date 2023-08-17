#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

string ban[5];
int seq[7];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int nums[7];
int res;

bool isGood() {

  queue<pair<int,int>> Q;
  bool chk[5][5] = {};
  bool vstchk[5][5] = {};
  for (int i = 0; i < 7; i++) {
    int x = seq[i] / 5;
    int y = seq[i] % 5;
    chk[x][y] = true;
    if (Q.empty()) {
      Q.push({x, y});
      vstchk[x][y] = true;
    }
  }

  int sum = 0, s = 0;
  while (!Q.empty()) {
    auto [x, y] = Q.front();
    Q.pop();
    sum++;
    s += ban[x][y] == 'S';

    for (int d = 0; d < 4; d++) {
      int nx = x + dx[d];
      int ny = y + dy[d];
      if (nx < 0 or nx >= 5 or ny < 0 or ny >= 5) continue;
      if (vstchk[nx][ny] or !chk[nx][ny]) continue;
      Q.push({nx, ny});
      vstchk[nx][ny] = true;
    }
  }
  return sum >= 7 and s >= 4;
}
void dfs(int k, int d) {
  if (k == 7) {
    if (isGood()) res++;
    return;
  }
  if (d == 25) return;

  seq[k] = d;
  dfs(k + 1, d + 1);
  dfs(k, d + 1);
}

void solve() {
  for (int i = 0; i < 5; i++) cin >> ban[i];

  dfs(0, 0);
  cout << res;
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