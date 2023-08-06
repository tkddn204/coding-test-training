#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int fac[10005];

void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> fac[i];

  int res = 0, cnt;
  for (int i = 1; i <= n; i++) {
    if (fac[i + 1] <= fac[i + 2]) {
      cnt = min(fac[i], min(fac[i + 1], fac[i + 2]));
      res += 7 * cnt;
      fac[i] -= cnt; fac[i + 1] -= cnt; fac[i + 2] -= cnt;

      cnt = min(fac[i], fac[i + 1]);
      res += 5 * cnt;
      fac[i] -= cnt; fac[i + 1] -= cnt;
    } else {
      cnt = min(fac[i], fac[i + 1] - fac[i + 2]);
      res += 5 * cnt;
      fac[i] -= cnt; fac[i + 1] -= cnt;

      cnt = min(fac[i], min(fac[i + 1], fac[i + 2]));
      res += 7 * cnt;
      fac[i] -= cnt; fac[i + 1] -= cnt; fac[i + 2] -= cnt;
    }
    res += 3 * fac[i];
    fac[i] = 0;
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