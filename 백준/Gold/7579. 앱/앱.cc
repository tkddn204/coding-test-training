#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define X first
#define Y second

int n, m, sum;
pair<int,int> app[101];
int dp[10001];

void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> app[i].X;
  for (int i = 1; i <= n; i++) {
    cin >> app[i].Y;
    sum += app[i].Y;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = sum; j > 0; j--) {
      if (j - app[i].Y >= 0) {
        dp[j] = max(dp[j], dp[j - app[i].Y] + app[i].X);
      }
    }
  }

  for (int j = 0; j <= sum; j++) {
    if (dp[j] >= m) {
      cout << j << endl;
      break;
    }
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