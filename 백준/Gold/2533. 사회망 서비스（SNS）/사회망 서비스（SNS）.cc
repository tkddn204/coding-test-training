#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

vector<int> tree[1000001];
int vst[1000001];
int dp[1000001][2];

void go(int cur) {
  vst[cur] = true;
  dp[cur][0] = 1;

  for (int nxt : tree[cur]) {
    if (vst[nxt]) continue;
    go(nxt);
    dp[cur][1] += dp[nxt][0];
    dp[cur][0] += min(dp[nxt][0], dp[nxt][1]);
  }
}

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }

  go(1);

  cout << min(dp[1][0], dp[1][1]);
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