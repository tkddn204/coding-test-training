#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

map<string, int> state;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
string endPan = "123456780";

void solve() {
  queue<tuple<int,int,string,int>> Q;
  int sx, sy;
  string s;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      char k;
      cin >> k;
      s += k;
      if (k == '0') {
        sx = i, sy = j;
      }
    }
  }
  Q.push({sx, sy, s, 0});
  state[s] = 0;

  int res = -1;
  while (!Q.empty()) {
    auto [x, y, pan, cnt] = Q.front(); Q.pop();

    if (pan == endPan) {
      res = cnt;
      break;
    }

    for (int d = 0; d < 4; d++) {
      int nx = x + dx[d];
      int ny = y + dy[d];

      if (nx < 0 or nx >= 3 or ny < 0 or ny >= 3) continue;
      swap(pan[x*3 + y], pan[nx*3 + ny]);
      string nxt = pan;
      swap(pan[x*3 + y], pan[nx*3 + ny]);
      if (state.find(nxt) != state.end()) {
        state[nxt] = min(state[nxt], cnt + 1);
        continue;
      }
      state[nxt] = cnt + 1;
      Q.push({nx, ny, nxt, cnt + 1});
    }
  }
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