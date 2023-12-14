#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n, m, k;
int graph[301][301];
int dp[301][301];

int go(int c, int k) {
  if (c == n) return 0;
  if (k == m) return -1e9;
  if (dp[c][k]) return dp[c][k];

  dp[c][k] = -1e9;
  for (int t = c + 1; t <= n; t++) {
    if (!graph[c][t]) continue;
    dp[c][k] = max(dp[c][k], go(t, k + 1) + graph[c][t]);
  }
  return dp[c][k];
}

void solve() {
  cin >> n >> m >> k;

  while (k--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a > b) continue;
    graph[a][b] = max(graph[a][b], c);
  }

  cout << go(1, 1);
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