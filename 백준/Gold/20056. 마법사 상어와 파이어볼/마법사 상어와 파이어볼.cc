#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

struct fireball {
  int w, s, d;
};

int n, m, k;
queue<fireball> mp[51][51];
queue<fireball> tmp[51][51];
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

void solve() {
  cin >> n >> m >> k;
  while (m--) {
    int r, c, w, s, d;
    cin >> r >> c >> w >> s >> d;
    mp[r][c].push({w, s, d});
  }

  while (k--) {
    for (int x = 1; x <= n; x++) {
      for (int y = 1; y <= n; y++) {
        if (mp[x][y].empty()) continue;
        while (!mp[x][y].empty()) {
          fireball f = mp[x][y].front(); mp[x][y].pop();
          int nx = x, ny = y;
          int s = f.s;
          while (s--) {
            nx += dx[f.d];
            ny += dy[f.d];
            if (nx < 1) nx = n;
            else if (nx >= n + 1) nx = 1;
            if (ny < 1) ny = n;
            else if (ny >= n + 1) ny = 1;
          }
          tmp[nx][ny].push(f);
        }
      }
    }

    for (int x = 1; x <= n; x++) {
      for (int y = 1; y <= n; y++) {
        if (tmp[x][y].empty()) continue;
        fireball sum = {0, 0, 0};
        int size = tmp[x][y].size();
        if (size == 1) {
          mp[x][y].push(tmp[x][y].front());
          tmp[x][y].pop();
        } else {
          int dir = 0;
          while (!tmp[x][y].empty()) {
            fireball cur = tmp[x][y].front(); tmp[x][y].pop();
            sum.w += cur.w;
            sum.s += cur.s;
            dir += (cur.d % 2);
          }
          sum.w /= 5;
          if (sum.w == 0) continue;
          sum.s /= size;
          int ord = !((dir == size) || dir == 0);
          for (int i = 0; i <= 6; i+=2) {
            fireball nxt = sum;
            nxt.d = i + ord;
            mp[x][y].push(nxt);
          }
        }
      }
    }
  }

  int res = 0;
  for (int x = 1; x <= n; x++) {
    for (int y = 1; y <= n; y++) {
      if (mp[x][y].empty()) continue;
      while (!mp[x][y].empty()) {
        fireball f = mp[x][y].front(); mp[x][y].pop();
        res += f.w;
      }
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