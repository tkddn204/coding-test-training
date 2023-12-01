#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int dp[1000001];

void solve() {
  int n;
  cin >> n;
  int res = 0;
  for (int i = 1; i <= n; i++) {
    int k;
    cin >> k;
    dp[k] = dp[k - 1] + 1;
    res = max(res, dp[k]);
  }
  cout << n - res;
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