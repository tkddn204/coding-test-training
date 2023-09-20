#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

struct fish {
  int num, dir;
  bool live;
};

fish mp[4][4];
int dx[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int mx;

void turn(int& d) {
  if (d == 8) d = 1;
  else d++;
}

void swap(fish& a, fish& b) {
  swap(a.num, b.num);
  swap(a.dir, b.dir);
  swap(a.live, b.live);
}

void move(int skx, int sky) {
  pair<int,int> fpoint[17];
  fish finfo[17];
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      int num = mp[i][j].num;
      fpoint[num] = {i, j};
      finfo[num] = mp[i][j];
    }
  }

  for (int f = 1; f <= 16; f++) {
    if (!finfo[f].live) continue;
    auto [x, y] = fpoint[f];

    int d = finfo[f].dir;
    for (int i = 0; i < 8; i++) {
      int nx = x + dx[d];
      int ny = y + dy[d];

      if (nx < 0 or nx >= 4 or ny < 0 or ny >= 4) {
        turn(d);
        continue;
      };
      
      if (nx == skx and ny == sky) {
        turn(d);
        continue;
      }
      
      // move
      swap(fpoint[mp[x][y].num], fpoint[mp[nx][ny].num]);
      swap(mp[x][y], mp[nx][ny]);
      mp[nx][ny].dir = d;
      break;
    }
  }
}

void dfs(int x, int y, int dir, int sum) {
  mx = max(mx, sum);

  fish premove[4][4];
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      premove[i][j] = mp[i][j];
    }
  }

  move(x, y);

  int nx = x, ny = y;
  for (int i = 0; i < 3; i++) {
    nx += dx[dir];
    ny += dy[dir];

    if (nx < 0 or nx >= 4 or ny < 0 or ny >= 4) break;
    if (!mp[nx][ny].live) continue;

    fish nxt = mp[nx][ny];
    swap(mp[x][y], mp[nx][ny]);
    mp[x][y].live = false;
    
    dfs(nx, ny, nxt.dir, sum + nxt.num);

    mp[x][y].live = true;
    swap(mp[x][y], mp[nx][ny]);
  }

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      mp[i][j] = premove[i][j];
    }
  }
}

void solve() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      int a, b;
      cin >> a >> b;
      mp[i][j] = {a, b, true};
    }
  }

  mp[0][0].live = false;
  dfs(0, 0, mp[0][0].dir, mp[0][0].num);

  cout << mx;
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