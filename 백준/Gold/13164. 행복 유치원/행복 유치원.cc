#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

int height[300001];
int cost[300001];

void solve() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> height[i];
  for (int i = 0; i < n - 1; i++) {
    cost[i] = height[i + 1] - height[i];
  }
  sort(cost, cost + n - 1);

  ll res = 0;
  for (int i = 0; i < n - k; i++) {
    res += cost[i];
  }
  cout << res;
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