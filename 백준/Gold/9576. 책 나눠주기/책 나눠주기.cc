#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> vp;

    while (m--) {
      int a, b;
      cin >> a >> b;
      vp.push_back({a, b});
    }
    sort(vp.begin(), vp.end(), [&](pair<int,int>& a, pair<int,int>& b) -> bool {
      if (a.second == b.second) return a.first < b.first;
      return a.second < b.second;
    });
    int book[n + 1] = {};
    int cnt = 0;
    for (auto [a, b]: vp) {
      bool chk = false;
      for (int i = a; i <= b; i++) {
        if (i > n) break;
        if (!book[i]) {
          book[i] = true;
          cnt++;
          break;
        }
      }
    }
    cout << cnt << endl;
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