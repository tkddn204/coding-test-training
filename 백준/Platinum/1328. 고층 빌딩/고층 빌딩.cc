#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define MOD 1000000007
#define ll long long

int dp[101][101][101];

void solve() {
  int n, l, r;
  cin >> n >> l >> r;

  dp[1][1][1] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= l; j++) { 
      for (int k = 1; k <= r; k++) {
        ll a = (ll)dp[i - 1][j][k] * (i - 2);
        int b = dp[i - 1][j][k - 1];
        int c = dp[i - 1][j - 1][k];
        dp[i][j][k] = (a + b + c) % MOD;
      }
    }
  }
  cout << dp[n][l][r];
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