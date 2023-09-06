#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define MOD 1000000007

int dp[4001][4001];

void solve() {
  string s, t;
  cin >> s >> t;

  int res = 0;
  for (int i = 1; i <= s.size(); i++) {
    for (int j = 1; j <= t.size(); j++) {
      if (s[i - 1] == t[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
        res = max(res, dp[i][j]);
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