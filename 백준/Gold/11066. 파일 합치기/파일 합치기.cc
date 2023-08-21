#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n;
int files[501];
int dp[501][501];
int sum[501];

int go(int st, int en) {
  if (st >= en) return dp[st][en] = 0;
  if (dp[st][en] != 1e9) return dp[st][en];

  for (int mid = st; mid < en; mid++) {
    int left = go(st, mid);
    int root = sum[en] - sum[st - 1];
    int right = go(mid + 1, en);
    dp[st][en] = min(dp[st][en], left + root + right);
  }

  return dp[st][en];
}

void solve() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> files[i];
      fill(dp[i], dp[i] + n + 1, 1e9);
      sum[i] = sum[i - 1] + files[i];
    }

    cout << go(1, n) << endl;
    // for (int i = 1; i <= n; i++) {
    //   for (int j = 1; j <= n; j++) {
    //     if (dp[i][j] == 1e9) cout << 0 << ' ';
    //     else cout << dp[i][j] << ' ';
    //   }
    //   cout << endl;
    // }
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