#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n;
int arr[505][505];
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int tdx[4][9] = {
	{0, -1, 1, -2, 2, -1, 1, -1, 1},
	{2, 1, 1, 0, 0, 0, 0, -1, -1},
	{0, -1, 1, -2, 2, -1, 1, -1, 1},
	{-2, -1, -1, 0, 0, 0, 0, 1, 1}
};
int tdy[4][9] = {
	{-2, -1, -1, 0, 0, 0, 0, 1, 1},
	{0, -1, 1, -2, 2, -1, 1, -1, 1},
	{2, 1, 1, 0, 0, 0, 0, -1, -1},
	{0, -1, 1, -2, 2, -1, 1, -1, 1}
};
int p[9] = {5, 10, 10, 2, 2, 7, 7, 1, 1};

void solve() {
  cin >> n;
  for (int i = 2; i < n + 2; i++) {
    for (int j = 2; j < n + 2; j++) {
      cin >> arr[i][j];
    }
  }

  int x = n / 2 + 2, y = n / 2 + 2;
  int d = 0;
  bool isEnd = false;
  for (int k = 1; k <= n; k++) {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < k; j++) {
        x += dx[d];
        y += dy[d];

        int sand = arr[x][y];
        for (int t = 0; t < 9; t++) {
          int dust = (arr[x][y] * p[t]) / 100;
          arr[x + tdx[d][t]][y + tdy[d][t]] += dust;
          sand -= dust;
        }
        arr[x + dx[d]][y + dy[d]] += sand;

        arr[x][y] = 0;
        if (x <= 2 and y <= 2) {
          isEnd = true;
          break;
        }
      }
      if (isEnd) break;
      d = (d + 1) % 4;
    }
  }

  int sum = 0;
  for (int i = 0; i < n + 4; i++) {
    for (int j = 0; j < n + 4; j++) {
      if (i < 2 or i >= n + 2 or j < 2 or j >= n + 2) {
        sum += arr[i][j];
      }
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