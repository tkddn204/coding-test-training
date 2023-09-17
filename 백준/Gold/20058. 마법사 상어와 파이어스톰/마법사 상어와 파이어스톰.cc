#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n, ns;
int ice[(1 << 6) + 1][(1 << 6) + 1];
bool vst[(1 << 6) + 1][(1 << 6) + 1];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void rotate(int sx, int sy, int xs) {
  int temp[xs][xs];
  for (int i = 0; i < xs; i++) {
    for (int j = 0; j < xs; j++) {
      temp[j][xs - i - 1] = ice[sx + i][sy + j];
    }
  }

  for (int i = 0; i < xs; i++) {
    for (int j = 0; j < xs; j++) {
      ice[sx + i][sy + j] = temp[i][j];
    }
  }
}

void meltice() {
  int temp[ns][ns];
  for (int i = 0; i < ns; i++)
    fill(temp[i], temp[i] + ns, 0);
  
  for (int i = 0; i < ns; i++) {
    for (int j = 0; j < ns; j++) {
      if (ice[i][j] == 0) continue;
      int cnt = 0;
      for (int d = 0; d < 4; d++) {
        int nx = i + dx[d];
        int ny = j + dy[d];

        if (nx < 0 || nx >= ns || ny < 0 || ny >= ns) continue;
        cnt += ice[nx][ny] > 0;
      }
      if (cnt < 3) temp[i][j] = -1;
    }
  }
  
  for (int i = 0; i < ns; i++) {
    for (int j = 0; j < ns; j++) {
      ice[i][j] += temp[i][j];
    }
  }
}

void printice() {
  for (int i = 0; i < ns; i++) {
    for (int j = 0; j < ns; j++) {
      cout << ice[i][j] ;
    }
    cout << endl;
  }
}

void solve() {
  int q;
  cin >> n >> q;
  ns = 1 << n;
  for (int i = 0; i < ns; i++) {
    for (int j = 0; j < ns; j++) {
      cin >> ice[i][j];
    }
  }
  while (q--) {
    int l;
    cin >> l;

    if (l > 0) {
      int xs = 1 << l;
      for (int i = 0; i < ns; i+= xs) {
        for (int j = 0; j < ns; j+= xs) {
          rotate(i, j, xs);
        }
      }
    }
    meltice();
    // printice();
  }

  // 얼음의 합
  int sum = 0;
  for (int i = 0; i < ns; i++) {
    for (int j = 0; j < ns; j++) {
      sum += ice[i][j];
    }
  }
  cout << sum << endl;

  // 가장 큰 덩어리가 차지하는 칸의 개수
  int mx = 0;
  for (int i = 0; i < ns; i++) {
    for (int j = 0; j < ns; j++) {
      if (ice[i][j] == 0 or vst[i][j]) continue;
      queue<pair<int,int>> Q;
      Q.push({i, j});
      vst[i][j] = true;
      int cnt = 1;
      while (!Q.empty()) {
        auto [x, y] = Q.front(); Q.pop();

        for (int d = 0; d < 4; d++) {
          int nx = x + dx[d];
          int ny = y + dy[d];

          if (nx < 0 or nx >= ns or ny < 0 or ny >= ns) continue;
          if (ice[nx][ny] == 0 or vst[nx][ny]) continue;
          Q.push({nx, ny});
          vst[nx][ny] = true;
          cnt++;
        }
      }
      mx = max(mx, cnt);
    }
  }
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