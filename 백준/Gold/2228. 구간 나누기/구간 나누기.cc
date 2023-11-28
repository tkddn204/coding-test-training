#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int num[101];
int dp[101][51];

int go(int c, int k) {
  if (k == 0) return 0;
  if (c < 1) return -1e8;
  if (dp[c][k] != -1) return dp[c][k];
  
  int sum = 0;
  dp[c][k] = go(c - 1, k);
  for (int i = c; i >= 1; i--) {
    sum += num[i];
    dp[c][k] = max(dp[c][k], go(i - 2, k - 1) + sum);
  }
  return dp[c][k];
}

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> num[i];
    fill(dp[i], dp[i] + m + 1, -1);
  }

  cout << go(n, m);
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