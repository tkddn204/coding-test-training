#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int nums[2001];
int dp[2001][2001];

void solve() {
  int n, m;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> nums[i];
    dp[i][i] = true;
    if (nums[i - 1] == nums[i])
      dp[i - 1][i] = 1;
  }

  for (int i = 2; i <= n; i++) {
    for (int j = 1; i + j <= n; j++) {
      if (nums[j] == nums[j + i] && dp[j + 1][i + j - 1] == 1) {
        dp[j][i + j] = 1;
      }
    }
  }

  cin >> m;
  while (m--) {
    int a, b;
    cin >> a >> b;
    cout << dp[a][b] << endl;    
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  solve();
  return 0;
}