#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int a[500001], b[500001];

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  sort(a, a + n);
  sort(b, b + m);
  int cnt = 0;
  vector<int> res;
  for (int i = 0; i < n; i++) {
    if (!binary_search(b, b + m, a[i])) {
      res.push_back(a[i]);
    }
  }
  if (res.empty()) {
    cout << 0;
  } else {
    cout << res.size() << endl;
    for (auto k : res) {
      cout << k << ' ';
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