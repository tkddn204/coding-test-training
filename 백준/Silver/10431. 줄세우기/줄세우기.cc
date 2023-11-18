#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    vector<int> v;
    int cnt = 0;
    for (int i = 0; i < 20; i++) {
      int k;
      cin >> k;
      v.push_back(k);
      int cur = v.size() - 1;
      while (cur > 0) {
        if (v[cur - 1] > v[cur]) swap(v[cur], v[cur - 1]);
        else break;
        cur--, cnt++;
      }
    }
    cout << n << ' ' << cnt << endl;
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