#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int arr[1001];
int dp[1001][31];

void solve() {
  int t, w;
  cin >> t >> w;
  for (int i = 1; i <= t; i++) {
    cin >> arr[i];
  }

  int res = 0;
  for (int i = 1; i <= t; i++) {
    dp[i][0] = dp[i - 1][0] + (arr[i] == 1);
    res = max(res, dp[i][0]);
    for (int j = 1; j <= w; j++) {
      int cur = arr[i] == ((j % 2) + 1);
      dp[i][j] = max(dp[i - 1][j] + cur, dp[i - 1][j - 1] + cur);
      res = max(res, dp[i][j]);
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