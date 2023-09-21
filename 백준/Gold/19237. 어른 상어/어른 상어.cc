#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n, m, k;
int mp[21][21];
int tmp[21][21];
pair<int,int> smell[21][21]; // { 번호, 사라지는시간 }
int shark[401];
int priority[401][5][5];
int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, -1, 1};
int t = 0;

bool onlyOne() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (mp[i][j] > 1) return false;
    }
  }
  return true;
}

void spray() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (smell[i][j].second == t) { // 냄새 제거
        smell[i][j] = {0, 0};
      }
      if (mp[i][j] == 0) continue;
      smell[i][j] = {mp[i][j], t + k}; // 냄새 뿌리기
    }
  }
}

void move() {
  for (int i = 0; i < n; i++)
    fill(tmp[i], tmp[i] + n, 0);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (mp[i][j] == 0) continue;

      int sk = mp[i][j];
      int dir = shark[sk];

      // 방향 정하기
      vector<int> candir;

      // 냄새가 없는 방향 고르기
      for (int d = 1; d <= 4; d++) {
        int nx = i + dx[d];
        int ny = j + dy[d];
        
        if (nx < 0 or nx >= n or ny < 0 or ny >= n) continue;
        if (smell[nx][ny].first == 0) {
          candir.push_back(d);
        }
      }
      
      // 다 냄새가 나면 자신의 냄새쪽으로 방향 고르기
      if (candir.empty()) {
        for (int d = 1; d <= 4; d++) {
          int nx = i + dx[d];
          int ny = j + dy[d];

          if (nx < 0 or nx >= n or ny < 0 or ny >= n) continue;
          if (smell[nx][ny].first == sk) {
            candir.push_back(d);
          }
        }
      }

      // cout << sk << ": ";
      // for (int d : candir) cout << d << ' ';
      // cout << endl;

      int mnVal = 5;
      int mnd = 0;
      for (int d: candir) {
        // 가능한 칸이 여러개면 우선순위대로
        if (mnVal > priority[sk][dir][d]) {
          mnVal = priority[sk][dir][d];
          mnd = d;
        }
      }
      shark[sk] = mnd;

      // 이동
      int nx = i + dx[mnd];
      int ny = j + dy[mnd];
      if (tmp[nx][ny] == 0 || tmp[nx][ny] > sk) {
        tmp[nx][ny] = sk;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      mp[i][j] = tmp[i][j];
      // cout << tmp[i][j] << ' ';
    }
    // cout << endl;
  }
  // cout << "--------------" << endl;
}

void solve() {
  cin >> n >> m >> k;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> mp[i][j];
    }
  }
  for (int i = 1; i <= m; i++) {
    int d;
    cin >> d;
    shark[i] = d;
  }
  for (int sk = 1; sk <= m; sk++) {
    for (int i = 1; i <= 4; i++) {
      int a, b, c, d;
      cin >> a >> b >> c >> d;
      priority[sk][i][a] = 1;
      priority[sk][i][b] = 2;
      priority[sk][i][c] = 3;
      priority[sk][i][d] = 4;
    }
  }

  // 1. 모든 상어가 자신의 냄새를 뿌림
  // 2. 이동방향 결정
  // 3. 냄새는 k 이동 후 사라짐

  spray();
  while (!onlyOne() && t++ <= 1000) {
    move();
    spray();
  }

  if (t > 1000) cout << -1;
  else cout << t;
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