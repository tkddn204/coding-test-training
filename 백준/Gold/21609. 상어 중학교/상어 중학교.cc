#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

struct blockgroup {
  int size;
  int rainbow;
  int row, col;
};

int n, m;
int mp[21][21];
bool vst[21][21];
bool maxvst[21][21];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void printMap() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (mp[i][j] == -2) cout << 'x' << ' ';
      else cout << mp[i][j] << ' ';
    }
    cout << endl;
  }
  cout << "-------------" << endl;
}

bool compare(blockgroup& a, blockgroup& b) {
  if (a.size == b.size) {
    if (a.rainbow == b.rainbow) {
      if (a.row == b.row) {
        return a.col < b.col;
      }
      return a.row < b.row;
    }
    return a.rainbow < b.rainbow;
  }
  return a.size < b.size;
}

int findgroup() {
  for (int k = 0; k < n; k++)
    fill(maxvst[k], maxvst[k] + n, false);

  blockgroup res = {0, 0, 0, 0};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (mp[i][j] <= 0) continue;
      
      for (int k = 0; k < n; k++)
        fill(vst[k], vst[k] + n, false);

      queue<pair<int,int>> Q;
      Q.push({i, j});
      vst[i][j] = true;

      blockgroup cur = {0, 0, i, j};
      while (!Q.empty()) {
        auto [x, y] = Q.front(); Q.pop();
        
        cur.size++;
        if (mp[x][y] == 0) cur.rainbow++;
        else if (cur.row > x || (cur.row == x && cur.col > y)) {
          cur.row = x;
          cur.col = y;
        }
        
        for (int d = 0; d < 4; d++) {
          int nx = x + dx[d];
          int ny = y + dy[d];

          if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
          if (vst[nx][ny]) continue;
          if (mp[nx][ny] == 0 || mp[nx][ny] == mp[i][j]) {
            Q.push({nx, ny});
            vst[nx][ny] = true;
          }
        }
      }
      if (compare(res, cur)) {
        res = cur;
        for (int x = 0; x < n; x++) {
          for (int y = 0; y < n; y++) {
            maxvst[x][y] = vst[x][y];
          }
        }
      }
    }
  }
  return res.size;
}

void removegroup() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if(maxvst[i][j]) mp[i][j] = -2;
    }
  }
}

void rotate() {
  int temp[21][21];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      temp[n - 1 - j][i] = mp[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      mp[i][j] = temp[i][j];
    }
  }
}

void gravity() {
  for (int j = 0; j < n; j++) {
    for (int i = n - 2; i >= 0; i--) {
      if (mp[i][j] <= -1) continue;
      int nxt = i;
      for (int k = i + 1; k < n; k++) {
        if (mp[k][j] >= -1) break;
        nxt = k;
      }
      swap(mp[i][j], mp[nxt][j]);
    }
  }
}

void solve() {
  cin >> n >> m;
  for (int i = 0; i < n ; i++) {
    for (int j = 0; j < n; j++) {
      cin >> mp[i][j];
    }
  }

  int score = 0;
  while (true) {
    int size = findgroup();
    if (size <= 1) break;
    score += size * size;
    removegroup();
    gravity();
    rotate();
    gravity();
  }
  cout << score;
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