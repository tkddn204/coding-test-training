#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int h, w;
char mp[103][103];
bool vst[103][103];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void solve() {
  int t;
  cin >> t;
  while (t--) {
    cin >> h >> w;

    int maxDoc = 0;
    for (int i = 0; i <= 103; i++)
      fill(vst[i], vst[i] + 103, false);
    
    for (int j = 0; j <= w + 1; j++) {
      mp[0][j] = '.';
      mp[h + 1][j] = '.';
    }
    for (int i = 1; i <= h; i++) {
      mp[i][0] = '.';
      for (int j = 1; j <= w; j++) {
        cin >> mp[i][j];
      }
      mp[i][w + 1] = '.';
    }

    int key[27] = {};
    string s;
    cin >> s;
    if (s[0] != '0') {
      for (auto c: s) key[c - 'a']++;
    }

    int res = 0;
    queue<pair<int,int>> Q;
    queue<pair<int,int>> door[27];
    Q.push({0, 0});
    vst[0][0] = true;
    while (!Q.empty()) {
      auto [x, y] = Q.front(); Q.pop();

      for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx < 0 or nx > h + 1 or ny < 0 or ny > w + 1) continue;
        if (vst[nx][ny] or mp[nx][ny] == '*') continue;
        vst[nx][ny] = true;
        res += mp[nx][ny] == '$';
        if (mp[nx][ny] >= 'A' and mp[nx][ny] <= 'Z') {
          int keyNum = mp[nx][ny] - 'A';
          if (!key[keyNum]) {
            door[keyNum].push({nx, ny});
            continue;
          }
        }
        if (mp[nx][ny] >= 'a' and mp[nx][ny] <= 'z') {
          int keyNum = mp[nx][ny] - 'a';
          if (key[keyNum] == 0) {
            key[keyNum]++;
            while (!door[keyNum].empty()) {
              Q.push(door[keyNum].front());
              door[keyNum].pop();
            }
          }
          mp[nx][ny] = '.';
        }
        Q.push({nx,ny});
      }
    }
    cout << res << endl;
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