#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n;
int arr[101][101];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
bool vst[101][101];
int minVal = INT_MAX, maxVal = -1;

bool chk(int mid) {
  for (int i = minVal; i <= maxVal; i++) {
    if (arr[0][0] < i || arr[0][0] > i + mid) continue;

    for (int k = 0; k < n; k++)
      fill(vst[k], vst[k] + n, false);

    queue<pair<int,int>> Q;
    Q.push({0, 0});
    vst[0][0] = true;
    while (!Q.empty()) {
      auto [x, y] = Q.front(); Q.pop();

      if (x == n - 1 and y == n - 1) return true;

      for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (vst[nx][ny]) continue;
        if (arr[nx][ny] < i || arr[nx][ny] > i + mid) continue;
        Q.push({nx, ny});
        vst[nx][ny] = true;
      }
    }
  }

  return false;
}

void solve() {
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
      minVal = min(minVal, arr[i][j]);
      maxVal = max(maxVal, arr[i][j]);
    }
  }

  int st = 0;
  int en = maxVal - minVal;
  int res = INT_MAX;
  while (st <= en) {
    int mid = (st + en) / 2;
    if (chk(mid)) {
      res = min(res, mid);
      en = mid - 1;
    } else st = mid + 1;
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