#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int w, h;
int mp[105][105];
bool vst[105][105];

int ewx[6] = {-1, 0, 1, 1, 0, -1};
int ewy[6] = {0, 1, 0, -1, -1, -1};
int owx[6] = {-1, 0, 1, 1, 0, -1};
int owy[6] = {1, 1, 1, 0, -1, 0};

void solve() {
  cin >> w >> h;

  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> mp[i][j];
    }
  }

  queue<pair<int,int>> Q;
  Q.push({0, 0});
  vst[0][0] = true;
  while (!Q.empty()) {
    auto [x, y] = Q.front(); Q.pop();

    for (int k = 0; k < 6; k++) {
      int kx, ky;
      if (x % 2 == 0) {
        kx = x + ewx[k];
        ky = y + ewy[k];
      } else {
        kx = x + owx[k];
        ky = y + owy[k];
      }

      if (kx < 0 or kx >= h + 2 or ky < 0 or ky >= w + 2) continue;
      if (vst[kx][ky] or mp[kx][ky]) continue;
      vst[kx][ky] = true;
      Q.push({kx, ky});
    }
  }

  int cnt = 0;
  for (int i = 1; i < h + 1; i++) {
    for (int j = 1; j < w + 1; j++) {
      if (mp[i][j] == 0) continue;

      for (int k = 0; k < 6; k++) {
        int kx, ky;
        if (i % 2 == 0) {
          kx = i + ewx[k];
          ky = j + ewy[k];
        } else {
          kx = i + owx[k];
          ky = j + owy[k];
        }

        if (kx < 0 or kx >= h + 2 or ky < 0 or ky >= w + 2) continue;
        if (vst[kx][ky]) cnt++;
      }
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