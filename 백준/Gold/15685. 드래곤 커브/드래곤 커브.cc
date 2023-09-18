#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int mp[101][101];
vector<int> dir;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

void printmp() {
  for (int i = 0; i < 21; i++) {
    for (int j = 0; j < 21; j++) {
      cout << mp[i][j];
    }
    cout << endl;
  }
  cout << "------------------" << endl;
}

void solve() {
  int n;
  cin >> n;
  while (n--) {
    int x, y, d, g;
    cin >> x >> y >> d >> g;    

    dir.clear();

    // 0세대
    mp[x][y] = 1;
    
    x += dx[d];
    y += dy[d];
    mp[x][y] = 1;
    dir.push_back(d);
    
    // 드래곤 커브를 만들어야 한다
    // 세대만큼 증가
    for (int k = 1; k <= g; k++) {
      // 시계 방향 90도 회전
      int size = dir.size();
      for (int i = size - 1; i >= 0; i--) {
        int nd = (dir[i] + 1) % 4;
        x += dx[nd];
        y += dy[nd];
        mp[x][y] = 1;
        dir.push_back(nd);
      }
    }
  }
  int cnt = 0;   
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      cnt += mp[i][j] and mp[i][j + 1] and mp[i + 1][j] and mp[i + 1][j + 1];
    }
  }
  cout << cnt;
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