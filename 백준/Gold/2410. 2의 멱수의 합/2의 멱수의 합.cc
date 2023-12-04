#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

int n;
ll dp[1000001];

ll go(int k) {
  if (dp[k]) return dp[k];
  return dp[k] = (go(k >> 1) + go(k - 1)) % (ll)1e9;
}

void solve() {
  cin >> n;

  dp[0] = 1; dp[1] = 2;
  cout << go(n >> 1);
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