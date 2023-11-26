#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n, d;
vector<pair<int,int>> sc[10001];
int res = 1e9;

void go(int cur, int cost) {
  if (cur == d) {
    res = min(res, cost);
    return;
  } else if (cur > d) return;

  for (; cur < d; cur++) {
    for (auto [nxt, nxtcost] : sc[cur]) {
      go(nxt, cost + nxtcost);
    }
    cost++;
  }
  res = min(res, cost);
}

void solve() {
  cin >> n >> d;
  for (int i = 0; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    if (b - a < c) continue;
    if (a > 10000) continue;
    sc[a].push_back({b, c});
  }

  go(0, 0);
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