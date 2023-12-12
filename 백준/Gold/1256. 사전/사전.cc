#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int dp[101][101];

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  
  for (int i = 1; i <= 100; i++) {
    dp[i][0] = dp[0][i] = 1;
  }
  
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      if (dp[i][j] > 1e9) dp[i][j] = 1e9;
    }
  }
  
  if (dp[n][m] < k) {
    cout << -1;
    return;
  }

  int a = n, b = m;
  while (a + b) {
    int cur = dp[a - 1][b];
    if (a == 0) {
      cout << 'z';
      b--;
    } else if (b == 0) {
      cout << 'a';
      a--;
    } else if (k <= cur) {
      cout << 'a';
      a--;
    } else {
      k -= cur;
      cout << 'z';
      b--;
    }
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