#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define MOD 1000000000

int n, k;
ll dp[201][201];


void solve() {
  cin >> n >> k;

  for (int i = 0; i <= n; i++) {
    dp[1][i] = 1;
  }

  for (int i = 2; i <= k; i++) {
    for (int j = 0; j <= n; j++) {
      for (int z = 0; z <= j; z++) {
        dp[i][j] += dp[i - 1][z];
      }
      dp[i][j] %= MOD;
    }
  }

  cout << dp[k][n];
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