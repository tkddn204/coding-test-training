#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

void solve() {
  ll x, y, w, s;
  cin >> x >> y >> w >> s;

  ll a = (x + y) * w;
  ll b = min(x, y) * s + abs(x - y) * w;

  ll res = min(a, b);
  if (abs(x - y) % 2) {
    res = min(res, (max(x, y) - 1) * s + w);
  } else {
    res = min(res, max(x, y) * s);
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