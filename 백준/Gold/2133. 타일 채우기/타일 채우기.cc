#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int dp[31];

void solve() {
  int n;
  cin >> n;
  
  if (n % 2 == 1) {
    cout << 0;
    return;
  }
  
  dp[0] = 1;
  dp[2] = 3;
  for (int i = 4; i <= n; i += 2) {
    dp[i] += dp[i - 2] * dp[2];
    for (int j = 0; j <= i - 4; j += 2) {
      dp[i] += dp[j] * 2;
    }
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