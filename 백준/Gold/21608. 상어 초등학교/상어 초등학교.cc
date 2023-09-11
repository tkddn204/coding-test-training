#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define MINPQ priority_queue<pair<int,int>, vector<pair<int,int>>, compare>

int n;
int order[401];
int good[401][4];
int room[401][401];
int emp[401][401];
queue<pair<int,int>> Q[4];

struct compare {
  bool operator() (pair<int,int>& a, pair<int,int>& b) {
    auto& [ax, ay] = a;
    auto& [bx, by] = b;
    if (emp[ax][ay] == emp[bx][by]) {
      if (ax == bx) return ay > by;
      return ax > bx;
    }

    return emp[ax][ay] < emp[bx][by];
  }
};

MINPQ pq;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void checkemp() {
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < n; y++) {
      int cnt = 0;
      for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (nx < 0 or nx >= n or ny < 0 or ny >= n) continue;
        cnt += !room[nx][ny];
      }

      emp[x][y] = cnt;
    }
  }
}

void checkgood(int st) {
  pq = MINPQ();
  int mx = 0;
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < n; y++) {
      if (room[x][y]) continue;
      int cnt = 0;
      for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (nx < 0 or nx >= n or ny < 0 or ny >= n) continue;
        for (int g = 0; g < 4; g++) {
          cnt += good[st][g] == room[nx][ny];
        }
      }
      if (cnt < mx) continue;
      if (cnt > mx) {
        mx = cnt;
        pq = MINPQ();
      }
      pq.push({x, y});
    }
  }
}

int satis() {
  int res = 0;
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < n; y++) {
      int st = room[x][y];
      int cnt = 0;
      for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (nx < 0 or nx >= n or ny < 0 or ny >= n) continue;
        for (int g = 0; g < 4; g++) {
          cnt += good[st][g] == room[nx][ny];
        }
      }
      if (cnt != 0) {
        int k = 1;
        while (cnt-- > 1) k *= 10;
        res += k;
      }
    }
  }
  return res;
}

void printroom() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << room[i][j] << ' ';
    }
    cout << endl;
  }
  cout << "-----------------" << endl;
}

void solve() {
  cin >> n;
  for (int i = 0; i < n * n; i++) {
    int k;
    cin >> k;
    order[i] = k;
    for (int j = 0; j < 4; j++) {
      int s;
      cin >> s;
      good[k][j] = s;
    }
  }

  for (int i = 0; i < n * n; i++) {
    checkemp();
    int st = order[i];
    checkgood(st);
    auto [x, y] = pq.top();
    room[x][y] = st;
    // printroom();
  }

  cout << satis();
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