#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

pair<int,int> arr[101];
int dp[100001];

void solve() {
  int n, k;
  cin >> n >> k;
  for (auto& [w, v] : arr) {
    cin >> w >> v;
  }

  for (int i = 0; i < n; i++) {
    auto [w, v] = arr[i];
    for (int j = k; j >= w; j--) {
      dp[j] = max(dp[j], dp[j - w] + v);
    }
  }
  cout << dp[k];
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