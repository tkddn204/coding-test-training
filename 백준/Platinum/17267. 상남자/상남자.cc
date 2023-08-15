#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

struct state {
  int x, y;
  int l, r;
};

int n, m;
string mp[1001];
bool vst[1001][1001];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void solve() {
  int l, r, sx, sy;
  
  cin >> n >> m;
  cin >> l >> r;
  
  queue<state> Q;
  for (int i = 0; i < n; i++) {
    cin >> mp[i];
    for (int j = 0; j < m; j++) {
      if (mp[i][j] == '2') {
        Q.push({i, j, l, r});
        vst[i][j] = true;
      }
    }
  }

  while (!Q.empty()) {
    state cur = Q.front(); Q.pop();

    for (int d = 0; d < 4; d++) {
      if (d < 2) {
        state nxt = cur;
        while (true) {
          nxt.x += dx[d];
          if (nxt.x < 0 or nxt.x >= n or nxt.y < 0 or nxt.y >= m) break;
          if (vst[nxt.x][nxt.y] || mp[nxt.x][nxt.y] == '1') break;
          vst[nxt.x][nxt.y] = true;
          state temp = nxt;
          Q.push(temp);
        }
      } else {
        state nxt = {
          cur.x + dx[d], cur.y + dy[d],
          cur.l - (d == 2), cur.r - (d == 3)
        };
        if (nxt.x < 0 or nxt.x >= n or nxt.y < 0 or nxt.y >= m) continue;
        if (vst[nxt.x][nxt.y] || mp[nxt.x][nxt.y] == '1') continue;
        if (d == 2 and nxt.l < 0) continue;
        if (d == 3 and nxt.r < 0) continue;
        vst[nxt.x][nxt.y] = true;
        Q.push(nxt);
      }
    }
  }

  int sum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      sum += vst[i][j];
      // cout << vst[i][j] << ' ';
    }
    // cout << endl;
  }
  cout << sum;

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