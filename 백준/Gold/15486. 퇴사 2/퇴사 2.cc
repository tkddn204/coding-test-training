#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int dp[1500001];

void solve() {
  int n;
  cin >> n;
  
  int money = 0;
  for (int i = 1; i <= n; i++) {
    int t, p;
    cin >> t >> p;

    money = max(money, dp[i]);
    if (i + t > n + 1) continue;

    dp[i + t] = max(money + p, dp[i + t]);
  }

  cout << max(money, dp[n + 1]);
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