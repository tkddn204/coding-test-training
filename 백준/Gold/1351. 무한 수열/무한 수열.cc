#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

ll n, p, q;
unordered_map<ll, ll> a;

ll go(ll x) {
  if (a[x]) return a[x];
  return a[x] = go(x / p) + go(x / q);
}

void solve() {
  cin >> n >> p >> q;
  a[0] = 1;
  cout << go(n);
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