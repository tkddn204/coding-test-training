#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define MOD 1000000000

int n;
int dp[101][10][1 << 10];

int rec(int idx, int nxt, int bit) {
  if (dp[idx][nxt][bit]) return dp[idx][nxt][bit];
  if (idx == n) return bit == (1 << 10) - 1;

  ll sum = 0;
  if (nxt + 1 < 10) {
    sum += rec(idx + 1, nxt + 1, bit | 1 << (nxt + 1));
  }
  if (nxt - 1 >= 0) {
    sum += rec(idx + 1, nxt - 1, bit | 1 << (nxt - 1));
  }
  return dp[idx][nxt][bit] = sum % MOD;
}

void solve() {
  cin >> n;
  ll res = 0;
  for (int i = 1; i < 10; i++) {
    res += rec(1, i, 1 << i);
    res %= MOD;
  }
  cout << res;
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