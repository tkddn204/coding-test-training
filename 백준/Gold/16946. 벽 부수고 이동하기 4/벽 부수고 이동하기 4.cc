#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n, m;
string mp[1001];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int vst[1001][1001];
int num[1001 * 1001];

void dfs(int x, int y, int idx) {
  vst[x][y] = idx;
  num[idx]++;
  for (int d = 0; d < 4; d++) {
    int nx = x + dx[d];
    int ny = y + dy[d];

    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
    if (vst[nx][ny] || mp[nx][ny] == '1') continue;
    dfs(nx, ny, idx);
  }
}

void solve() {
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> mp[i];
  }

  int idx = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mp[i][j] == '1' || vst[i][j]) continue;
      
      dfs(i, j, idx++);
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mp[i][j] == '0') {
        cout << 0;
        continue;
      }

      int cnt = 1;
      set<int> s;
      for (int d = 0; d < 4; d++) {
        int nx = i + dx[d];
        int ny = j + dy[d];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (mp[nx][ny] == '1') continue;
        s.insert(vst[nx][ny]);
      }
      for (int k : s) cnt += num[k];
      cout << cnt % 10;
    }
    cout << endl;
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