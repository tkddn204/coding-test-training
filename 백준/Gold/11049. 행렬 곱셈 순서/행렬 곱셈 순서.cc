#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n;
int r[501], c[501];
int dp[501][501];

int rec(int st, int en) {
  if (st >= en) return 0;
  if (dp[st][en] != -1) return dp[st][en];

  dp[st][en] = INT_MAX;
  for (int k = st; k <= en; k++) {
    int left = rec(st, k);
    int root = r[st]*c[k]*c[en];
    int right = rec(k + 1, en);
    dp[st][en] = min(dp[st][en], left + root + right);
  }

  return dp[st][en];
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> r[i] >> c[i];
    fill(dp[i], dp[i] + n + 1, -1);
  }
  cout << rec(1, n);
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