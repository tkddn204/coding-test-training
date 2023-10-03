#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int dp[101][101][101];

void solve() {
  string a, b, c;
  cin >> a >> b >> c;

  int asize = a.size();
  int bsize = b.size();
  int csize = c.size();
  a = ' ' + a; b = ' ' + b; c = ' ' + c;

  for(int i = 1; i <= asize; i++) {
    for (int j = 1; j <= bsize; j++) {
      for (int k = 1; k <= csize; k++) {
        if (a[i] == b[j] && b[j] == c[k]) {
          dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
        } else {
          dp[i][j][k] = max(
            dp[i - 1][j][k],
            max(dp[i][j - 1][k], dp[i][j][k - 1])
          );
        }
      }
    }
  }
  cout << dp[asize][bsize][csize];
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