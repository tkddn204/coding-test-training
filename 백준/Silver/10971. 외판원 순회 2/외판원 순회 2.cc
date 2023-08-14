#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n;
int w[17][17];
int dp[17][(1 << 16) + 1];

int dfs(int cur, int mask) {
  if (mask == (1 << n) - 1) {
    return w[cur][0] > 0 ? w[cur][0] : 1e9;
  }
  if (dp[cur][mask] > 0) {
    return dp[cur][mask];
  }

  dp[cur][mask] = 1e9;
  
  for (int i = 0; i < n; i++) {
    if (w[cur][i] == 0) continue;
    if (mask & (1 << i)) continue;
    int cost = dfs(i, mask | (1 << i));
    dp[cur][mask] = min(dp[cur][mask], w[cur][i] + cost);
  }

  return dp[cur][mask];
}

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> w[i][j];
    }
  }

  cout << dfs(0, 1);
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