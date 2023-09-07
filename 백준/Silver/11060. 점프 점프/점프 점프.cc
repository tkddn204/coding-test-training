#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int miro[1001];
int dp[1001];

void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> miro[i];
    dp[i] = 1e9;
  }

  dp[1] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= i + miro[i]; j++) {
      if (j > n) break;
      dp[j] = min(dp[j], dp[i] + 1);
    }
  }

  if (dp[n] == 1e9) cout << -1;
  else cout << dp[n];
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