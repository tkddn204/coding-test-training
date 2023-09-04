#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define MOD 1000000

ll dp[5001];

void solve() {
  string s;
  cin >> s;

  int size = s.size();
  s = "0" + s;

  dp[0] = 1;
  for (int i = 1; i <= size; i++) {
    if (s[i] > '0') {
      dp[i] = (dp[i] + dp[i - 1]) % MOD;
    }

    if (s[i - 1] == '1') {
      dp[i] = (dp[i] + dp[i - 2]) % MOD;
    } else if (s[i - 1] == '2' && s[i] <= '6') {
      dp[i] = (dp[i] + dp[i - 2]) % MOD;
    }
  }
  cout << dp[size];
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