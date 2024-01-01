#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int jum[10001];
int dp[10001];

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> jum[i];

  int mx, mn;
  for (int i = 0; i < n; i++) {
    mx = mn = jum[i];
    for (int j = i; j >= 0; j--) {
      mx = max(mx, jum[j]);
      mn = min(mn, jum[j]);
      dp[i + 1] = max(dp[i + 1], dp[j] + mx - mn);
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