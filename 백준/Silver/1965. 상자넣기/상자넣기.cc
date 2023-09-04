#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int box[1001];
int dp[1001];

void solve() {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) cin >> box[i];

  int res = 1;
  for (int i = 1; i <= n; i++) {
    dp[i] = 1;
    for (int j = 1; j < i; j++) {
      if (box[j] < box[i]) {
        dp[i] = max(dp[i], dp[j] + 1);
        res = max(res, dp[i]);
      }
    }
  }
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