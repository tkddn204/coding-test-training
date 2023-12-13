#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

struct item {
  int v, c, k;
};

int n, m;
item items[101];
int dp[10001];

void solve() {
  cin >> n >> m;
  for (auto& [v, c, k]: items) {
    cin >> v >> c >> k;
    int d = 1;
    while (k) {
      int t = min(k, d);
      for (int i = m; i >= v * t; i--) {
        dp[i] = max(dp[i], dp[i - v * t] + c * t);
      }
      d *= 2;
      k -= t;
    }
  }
  cout << *max_element(dp, dp + m + 1);
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