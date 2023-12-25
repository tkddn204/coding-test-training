#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define MOD 1000000009

ll dp[1000001];

void solve() {
  int t;
  cin >> t;

  dp[1] = 1; dp[2] = 2; dp[3] = 4;
  for (int i = 4; i <= 1000000; i++) {
    dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD;
  }

  while (t--) {
    ll n;
    cin >> n;
    cout << dp[n] << endl;
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