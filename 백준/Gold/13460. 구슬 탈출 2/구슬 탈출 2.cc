#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define X first
#define Y second

int n, m;
string board[11];
int vst[11][11][11][11];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
pair<int, int> red;
pair<int, int> blue;

struct state {
  pair<int,int> red, blue;
  int cnt;
};

void tilt(int& rx, int& ry, int& d, int& cnt) {
  while (
    board[rx + dx[d]][ry + dy[d]] != '#' and
    board[rx][ry] != 'O'
  ) {
    rx += dx[d], ry += dy[d];
    cnt++;
  }
}

void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> board[i];
    for (int j = 0; j < m; j++) {
      if (board[i][j] == 'R') red = {i, j};
      if (board[i][j] == 'B') blue = {i, j};
    }
  }

  queue<state> Q;
  Q.push({red, blue, 0});
  vst[red.X][red.Y][blue.X][blue.Y] = true;
  while(!Q.empty()) {
    state st = Q.front(); Q.pop();
    auto [rx, ry] = st.red;
    auto [bx, by] = st.blue;
    int cnt = st.cnt;

    if (cnt >= 10) break;

    for (int d = 0; d < 4; d++) {
      int nrx = rx, nry = ry;
      int nbx = bx, nby = by;
      int rcnt = 0, bcnt = 0;
      int ncnt = cnt + 1;
      tilt(nrx, nry, d, rcnt);
      tilt(nbx, nby, d, bcnt);

      if (board[nbx][nby] == 'O') continue;
      if (board[nrx][nry] == 'O') {
        cout << ncnt;
        return;
      }
      
      if (nrx == nbx and nry == nby) {
        if (rcnt > bcnt) nrx -= dx[d], nry -= dy[d];
        else nbx -= dx[d], nby -= dy[d];
      }

      if (vst[nrx][nry][nbx][nby]) continue;
      vst[nrx][nry][nbx][nby] = true;
      Q.push({{nrx,nry}, {nbx,nby}, ncnt});
    }
  }
  cout << -1;
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