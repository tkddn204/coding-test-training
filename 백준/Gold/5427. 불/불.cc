#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

string building[1001];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int firevst[1001][1001];
int sangvst[1001][1001];

void solve() {
  int t;
  cin >> t;
  while (t--) {
    int w, h;
    cin >> w >> h;
    for (int i = 0; i < h; i++) {
      fill(firevst[i], firevst[i] + w, INT_MAX);
      fill(sangvst[i], sangvst[i] + w, -1);
    }
    queue<pair<int, int>> fireQ;
    queue<pair<int, int>> sangQ;
    for (int i = 0; i < h; i++) {
      cin >> building[i];
      for (int j = 0; j < w; j++) {
        if (building[i][j] == '*') {
          fireQ.push({i, j});
          firevst[i][j] = 0;
        } else if (building[i][j] == '@') {
          sangQ.push({i, j});
          sangvst[i][j] = 0;
        }
      }
    }

    int fireSize = fireQ.size();
    // 불이 번지고
    while (!fireQ.empty()) {
      auto [x, y] = fireQ.front(); fireQ.pop();
      for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx < 0 or nx >= h or ny < 0 or ny >= w) continue;
        if (building[nx][ny] == '#' or building[nx][ny] == '*') continue;
        if (firevst[nx][ny] != INT_MAX) continue;
        fireQ.push({nx, ny});
        firevst[nx][ny] = firevst[x][y] + 1;
      }
    }

    int time = 0;
    bool escape = false;
    
    // 상범이가 이동
    while (!sangQ.empty()) {
      auto [x, y] = sangQ.front(); sangQ.pop();
      for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx < 0 or nx >= h or ny < 0 or ny >= w) {
          escape = true;
          time = sangvst[x][y] + 1;
          break;
        }
        if (building[nx][ny] == '#' or building[nx][ny] == '*') continue;
        if (firevst[nx][ny] <= sangvst[x][y] + 1) continue;
        if (sangvst[nx][ny] >= 0) continue;
        sangQ.push({nx, ny});
        sangvst[nx][ny] = sangvst[x][y] + 1;
      }
      if (escape) break;
    }

    if (escape) cout << time << endl;
    else cout << "IMPOSSIBLE" << endl;
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