#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

int n;
int pan[101][101];
ll dp[101][101];

void solve() {
  cin >> n;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> pan[i][j];
    }
  }

  dp[1][1] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i != n and i + pan[i][j] <= n)
        dp[i + pan[i][j]][j] += dp[i][j];
      if (j != n and j + pan[i][j] <= n)
        dp[i][j + pan[i][j]] += dp[i][j];
    }
  }

  cout << dp[n][n];
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