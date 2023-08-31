#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n;
int mp[21][21];
int vst[21][21];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int bx, by;
int babysize = 2, eat = 0;
int t;

int moveAndEatFish() {
  queue<pair<int, int>> Q;
  for (int i = 0; i < n; i++)
    fill(vst[i], vst[i] + n, -1);
  
  Q.push({bx, by});
  vst[bx][by] = 0;
  while(!Q.empty()) {
    int x, y;
    tie(x, y) = Q.front(); Q.pop();

    for (int d = 0; d < 4; d++) {
      int nx = x + dx[d];
      int ny = y + dy[d];
      if (nx < 0 or nx >= n or ny < 0 or ny >= n) continue;
      if (mp[nx][ny] > babysize || vst[nx][ny] > -1) continue;
      Q.push({nx, ny});
      vst[nx][ny] = vst[x][y] + 1;
    }
  }

  int mindist = 400;
  int fx = -1, fy = -1;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = n - 1; j >= 0; j--) {
      if (vst[i][j] > 0 and vst[i][j] <= mindist
            and mp[i][j] > 0 and mp[i][j] < babysize) {
        mindist = vst[i][j];
        fx = i, fy = j;
      }
    }
  }

  // cout << t + vst[fx][fy] << "-------------" << endl;
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < n; j++) {
  //     if (i == fx and j == fy) cout << "■";
  //     else cout << mp[i][j];
  //     if (vst[i][j] == -1) vst[i][j] = 0;
  //     cout << '(' << vst[i][j] << ')' << ' ';
  //   }
  //   cout << endl;
  // }
  //cout << bx << "," << by << " -> " << fx << "," << fy << endl;
  if (fx == -1 and fy == -1) return -1;
  eat++;
  if (eat == babysize) {
    babysize++;
    eat = 0;
  }
  bx = fx, by = fy;
  mp[bx][by] = 0;
  return mindist;
}

void solve() {
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> mp[i][j];
      if (mp[i][j] == 9) {
        bx = i, by = j;
        mp[i][j] = 0;
      }
    }
  }
  int dist;
  while((dist = moveAndEatFish()) > 0) {
    t += dist;
  }
  cout << t;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  solve();
  return 0;
}