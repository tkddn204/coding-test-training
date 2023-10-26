#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n, m, k;
int area[11][11];
int add[11][11];
deque<int> tree[11][11];

void springAndSummer() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (tree[i][j].empty()) continue;

      queue<int> live;
      while (!tree[i][j].empty() && tree[i][j].front() <= area[i][j]) {
        area[i][j] -= tree[i][j].front();
        live.push(tree[i][j].front() + 1);
        tree[i][j].pop_front();
      }
      while (!tree[i][j].empty()) {
        area[i][j] += tree[i][j].front() / 2;
        tree[i][j].pop_front();
      }
      while (!live.empty()) {
        tree[i][j].push_back(live.front());
        live.pop();
      }
    }
  }
}

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void automn() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (tree[i][j].empty()) continue;
      
      for (int k = 0; k < tree[i][j].size(); k++) {
        if (tree[i][j][k] % 5 == 0) {
          for (int d = 0; d < 8; d++) {
            int nx = i + dx[d];
            int ny = j + dy[d];
            if (nx < 1 || nx >= n + 1 || ny < 1 || ny >= n + 1) continue;
            tree[nx][ny].push_front(1);
          }
        }
      }
    }
  }
}

void winter() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      area[i][j] += add[i][j];
    }
  }
}

void solve() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      area[i][j] = 5;
      cin >> add[i][j];
    }
  }
  while (m--) {
    int x, y, z;
    cin >> x >> y >> z;
    tree[x][y].push_back(z);
  }

  while (k--) {
    springAndSummer();
    automn();
    winter();
  }

  int sum = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      sum += tree[i][j].size();
    }
  }
  cout << sum;
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