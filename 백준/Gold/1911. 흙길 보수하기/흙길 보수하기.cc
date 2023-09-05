#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

pair<int,int> water[10001];

void solve() {
  int n, l;
  cin >> n >> l;
  int end = 0;
  for (int i = 0; i < n; i++) {
    auto& [x, y] = water[i];
    cin >> x >> y;
    y = max(y, end);
  }

  sort(water, water + n);

  int st = 0;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    auto [x, y] = water[i];
    if (st >= y) continue;
    st = max(st, x);
    int need = (y - (st + 1)) / l + 1;
    st += need * l;
    cnt += need;
  }
  cout << cnt;
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