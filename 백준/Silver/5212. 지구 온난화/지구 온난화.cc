#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

string mp[11];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void solve() {
  int r, c;
  cin >> r >> c;
  for (int i = 0; i < r; i++) {
    cin >> mp[i];
  }

  char temp[r][c];
  for (int i = 0; i < r; i++)
    fill(temp[i], temp[i] + c, '.');

  int mxx = 0, mxy = 0;
  int mnx = 11, mny = 11;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (mp[i][j] == '.') continue;
      int cnt = 0;
      for (int d = 0; d < 4; d++) {
        int nx = i + dx[d];
        int ny = j + dy[d];
        if (nx < 0 or nx >= r or ny < 0 or ny >= c) {
          cnt ++;
          continue;
        }
        cnt += mp[nx][ny] == '.';
      }
      if (cnt >= 3) temp[i][j] = '.';
      else {
        temp[i][j] = 'X';
        mxx = max(mxx, i); mxy = max(mxy, j);
        mnx = min(mnx, i); mny = min(mny, j);
      }
    }
  }
  
  for (int i = mnx; i <= mxx; i++) {
    for (int j = mny; j <= mxy; j++) {
      cout << temp[i][j];
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