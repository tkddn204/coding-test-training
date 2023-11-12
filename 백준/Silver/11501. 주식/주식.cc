#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

int j[1000001];

void solve() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> j[i];

    ll res = 0;
    ll maxval = 0;
    queue<ll> buy;
    for (int i = n - 1; i >= 0; i--) {
      maxval = max(maxval, (ll)j[i]);
      res += maxval - j[i];
    }
    cout << res << endl;
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