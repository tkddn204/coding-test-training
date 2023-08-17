#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n, m;
int factory[101][101];
int vst[101][101][5];
int dx[] = {0, 0, 0, 1, -1};
int dy[] = {0, 1, -1, 0, 0};

struct robot {
  int x, y;
  int dir;
};

bool go(robot& cur, int k) {
  int d = cur.dir;
  for (int i = 1; i <= k; i++) {
    int nx = cur.x + dx[d] * i;
    int ny = cur.y + dy[d] * i;
    if (nx < 1 or nx >= n + 1 or ny < 1 or ny >= m + 1) return false;
    if (factory[nx][ny] == 1) return false;
  }
  cur.x += dx[d] * k;
  cur.y += dy[d] * k;
  return vst[cur.x][cur.y][d] == -1;
}

bool turn(robot& cur, bool flag) {
  if (flag) { // 왼쪽
    int dir[5] = {0, 4, 3, 1, 2};
    cur.dir = dir[cur.dir];
  } else { // 오른쪽
    int dir[5] = {0, 3, 4, 2, 1};
    cur.dir = dir[cur.dir];
  }
  return vst[cur.x][cur.y][cur.dir] == -1;
}

void solve() {
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> factory[i][j];
      for (int k = 0; k < 5; k++) {
        vst[i][j][k] = -1;
      }
    }
  }

  robot st, en;
  cin >> st.x >> st.y >> st.dir;
  cin >> en.x >> en.y >> en.dir;

  queue<robot> Q;
  Q.push(st);
  vst[st.x][st.y][st.dir] = 0;
  while(!Q.empty()) {
    auto cur = Q.front(); Q.pop();

    if (cur.x == en.x and cur.y == en.y and cur.dir == en.dir) {
      cout << vst[en.x][en.y][en.dir];
      break;
    }

    for (int k = 1; k <= 3; k++) {
      robot nxt = cur;
      if (go(nxt, k)) {
        Q.push(nxt);
        vst[nxt.x][nxt.y][nxt.dir] = 
          vst[cur.x][cur.y][cur.dir] + 1;
      }
    }
    for (int d = 0; d <= 1; d++) {
      robot nxt = cur;
      if (turn(nxt, d)) {
        Q.push(nxt);
        vst[nxt.x][nxt.y][nxt.dir] = 
          vst[cur.x][cur.y][cur.dir] + 1;
      }
    }
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