#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

struct bessie {
  int t, a, b, h;
};

int vst[5000001];

void solve() {
  int t, a, b;
  cin >> t >> a >> b;

  queue<bessie> Q;
  Q.push({0, 0, 0, 0});

  int res = 0;
  while (!Q.empty()) {
    auto [ct, ca, cb, ch] = Q.front(); Q.pop();
    if (vst[ct]) continue;
    vst[ct] = true;
    res = max(res, ct);
    if (res == t) break;

    if (ct + a <= t) {
      Q.push({ct + a, 1, cb, ch});
    }
    if (ct + b <= t) {
      Q.push({ct + b, ca, 1, ch});
    }
    if (!ch && ct > 0) {
      Q.push({ct / 2, ca, cb, 1});
    }
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