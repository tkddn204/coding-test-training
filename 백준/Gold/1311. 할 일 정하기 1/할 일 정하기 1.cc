#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n;
int d[21][21];
int dp[(1 << 21) + 1];

int rec(int k, int bit) {
  if (k > n) return 0;
  if (dp[bit]) return dp[bit];

  dp[bit] = 1e9;
  for (int i = 1; i <= n; i++) {
    if (bit & (1 << i)) continue;
    dp[bit] = min(dp[bit],
                    rec(k + 1, bit | (1 << i)) + d[k][i]);
  }

  return dp[bit];
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> d[i][j];
    }
  }

  cout << rec(1, 0);
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