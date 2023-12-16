#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n;
int arr[100001];
int dp[100001][2];

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> arr[i];

  dp[1][0] = dp[1][1] = arr[1];
  int res = arr[1];
  for (int i = 2; i <= n; i++)  {
    dp[i][0] = max(dp[i - 1][0] + arr[i], arr[i]);
    dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]);
    res = max({res, dp[i][0], dp[i][1]});
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