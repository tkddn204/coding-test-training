#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n;
string mp[51];
int vst[51][51][2];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct Log {
  int x, y, d;
};

bool carry(Log& cur, int dir) {
  pair<int,int> lcur, rcur;
  pair<int,int> mcur = {cur.x, cur.y};

  if (cur.d == 0) { // 가로
    lcur = {cur.x, cur.y - 1};
    rcur = {cur.x, cur.y + 1};
  } else { // 세로
    lcur = {cur.x - 1, cur.y};
    rcur = {cur.x + 1, cur.y};
  }

  for (auto [x, y] : {lcur, mcur, rcur}) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    
    if (nx < 0 or nx >= n or ny < 0 or ny >= n) return false;
    if (mp[nx][ny] == '1') return false;
  }
  
  cur.x += dx[dir];
  cur.y += dy[dir];

  return true;
}

bool rotate(Log& cur) {

  // 1체크
  for (int i = -1; i < 2; i++) {
    for (int j = -1; j < 2; j++) {
      int nx = cur.x + i;
      int ny = cur.y + j;
      if (nx < 0 or nx >= n or ny < 0 or ny >= n) return false;
      if (mp[nx][ny] == '1') return false;
    }
  }

  // 돌려
  pair<int,int> lcur, rcur;
  int nd = !cur.d;

  if (nd == 0) { // 가로
    lcur = {cur.x, cur.y - 1};
    rcur = {cur.x, cur.y + 1};
  } else { // 세로
    lcur = {cur.x - 1, cur.y};
    rcur = {cur.x + 1, cur.y};
  }

  for (auto [nx, ny] : {lcur, rcur}) {
    if (nx < 0 or nx >= n or ny < 0 or ny >= n) return false;
    if (mp[nx][ny] == '1') return false;
  }

  cur.d = nd;

  return true;
}

void solve() {
  cin >> n;

  vector<pair<int,int>> st, en;
  memset(vst, -1, sizeof(vst));
  for (int i = 0; i < n; i++) {
    cin >> mp[i];
    for (int j = 0; j < n; j++) {
      if (mp[i][j] == 'B') {
        st.push_back({i, j});
      } else if (mp[i][j] == 'E') {
        en.push_back({i, j});
      }
    }
  }
  
  auto [stx, sty] = st[1];
  auto [enx, eny] = en[1];
  int std = st[0].second == st[1].second;
  int end = en[0].second == en[1].second;
  Log stlog = {stx, sty, std};

  queue<Log> Q;
  Q.push(stlog);
  vst[stx][sty][std] = 0;
  int res = 0;
  while (!Q.empty()) {
    auto cur = Q.front(); Q.pop();

    // 옮기기
    for (int d = 0; d < 4; d++) {
      Log nxt = cur;
      if (carry(nxt, d)) {
        if (vst[nxt.x][nxt.y][nxt.d] > -1) continue;
        vst[nxt.x][nxt.y][nxt.d] = vst[cur.x][cur.y][cur.d] + 1;
        Q.push(nxt);
      }
    }

    // 회전
    Log nxt = cur;
    if (rotate(nxt)) {
      if (vst[nxt.x][nxt.y][nxt.d] > -1) continue;
      vst[nxt.x][nxt.y][nxt.d] = vst[cur.x][cur.y][cur.d] + 1;
      Q.push(nxt);
    }

    if (vst[enx][eny][end] > -1) {
      res = vst[enx][eny][end];
      break;
    }
  }
  cout << res;
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