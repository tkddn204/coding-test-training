#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n, m;
int arr[51][51];
int vst[51][51];
int dx[] = {0, 0, -1, -1 ,-1, 0, 1, 1, 1};
int dy[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
queue<pair<int,int>> precloud;
queue<pair<int,int>> cloud;

void printArr() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << arr[i][j] << ' ';
    }
    cout << endl;
  }
  cout << "-----------" << endl;
}

void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> arr[i][j];
    }
  }

  cloud.push({n, 1});
  cloud.push({n, 2});
  cloud.push({n - 1, 1});
  cloud.push({n - 1, 2});

  while (m--) {
    int d, s;
    cin >> d >> s;
    
    // 모든 구름 이동 + 물 증가 + 사라짐
    while(!cloud.empty()) {
      auto [x, y] = cloud.front(); cloud.pop();

      int go = s;
      int nx = x, ny = y;
      while (go--) {
        nx += dx[d];
        ny += dy[d];
        
        if (nx < 1) nx = n;
        if (nx > n) nx = 1;
        if (ny < 1) ny = n;
        if (ny > n) ny = 1;
      }
      arr[nx][ny]++;
      precloud.push({nx, ny});
    }
    
    // 물복사버그
    int size = precloud.size();
    while (size--) {
      auto [x, y] = precloud.front(); precloud.pop();

      for (int d = 2; d <= 8; d+=2) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx < 1 or nx > n or ny < 1 or ny > n) continue;
        arr[x][y] += arr[nx][ny] > 0;
      }
      precloud.push({x, y});
    }

    // 구름생김
    for (int i = 1; i <= n; i++)
      fill(vst[i], vst[i] + n + 1, 0);
    while (!precloud.empty()) {
      auto [x, y] = precloud.front(); precloud.pop();
      vst[x][y] = true;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (vst[i][j]) continue;
        if (arr[i][j] >= 2) {
          cloud.push({i, j});
          arr[i][j] -= 2;
        }
      }
    }
  }

  // printArr();
  
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      sum += arr[i][j];
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