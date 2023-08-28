#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define T first
#define P second

pair<int, int> work[16];
int dp[16];

void solve() {
  int n, t, p;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> t >> p;
    work[i] = {t, p};
  }

  for (int i = n; i >= 1; i--) {
    int until = i + work[i].T - 1;
    if (until > n) dp[i] = dp[i + 1];
    else dp[i] = max(dp[i + work[i].T] + work[i].P, dp[i + 1]);
  }

  int res = 0;
  for (int i = 1; i <= n; i++) {
    res = max(res, dp[i]);
  }
  cout << res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  solve();
  return 0;
}