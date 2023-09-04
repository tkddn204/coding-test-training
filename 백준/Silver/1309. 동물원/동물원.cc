#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define MOD 9901

int dp[100001];

void solve() {
  int n;
  cin >> n;

  dp[0] = 1;
  dp[1] = 3;
  for (int i = 2; i <= n; i++) {
    dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % MOD;
  }

  cout << dp[n];
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