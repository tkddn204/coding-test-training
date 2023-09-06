#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

ll dp[41];

void solve() {
  int n, m;
  cin >> n >> m;

  dp[0] = dp[1] = 1;
  for (int i = 2; i <= n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  ll res = 1;
  int st = 0;
  while (m--) {
    ll en;
    cin >> en;
    res *= dp[en - st - 1];
    st = en;
  }
  res *= dp[n - st];
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