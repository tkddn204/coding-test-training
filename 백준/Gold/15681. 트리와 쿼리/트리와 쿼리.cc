#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n, r, q;
vector<int> edge[100001];
int dp[100001];

int dfs(int x, int prev) {
  if (dp[x]) return dp[x];
  dp[x] = 1;
  for (int e : edge[x]) {
    if (e == prev) continue;
    dp[x] += dfs(e, x);
  }

  return dp[x];
}

void solve() {
  cin >> n >> r >> q;

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    edge[u].push_back(v);
    edge[v].push_back(u);
  }

  dfs(r, -1);

  for (int i = 0; i < q; i++) {
    int k;
    cin >> k;
    cout << dp[k] << endl;
  }
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