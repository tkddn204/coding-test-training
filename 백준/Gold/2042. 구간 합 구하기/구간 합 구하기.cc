#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

int n, m, k, lf;
ll num[4000004];

void init() {
  for (int i = lf - 1; i > 0; i--) {
    num[i] = num[i * 2] + num[(i * 2) + 1];
  }
}

void update(int b, ll c) {
  b += lf - 1;
  num[b] = c;
  while (b /= 2) {
    num[b] = num[b * 2] + num[(b * 2) + 1];
  }
}

ll sum(int from , int to) {
  from += lf - 1;
  to += lf - 1;
  ll res = 0;
  while (from <= to) {
    if (from % 2 == 1) res += num[from];
    if (to % 2 == 0) res += num[to];

    from = (from + 1) / 2;
    to = (to - 1) / 2;
  }
  return res;
}

void solve() {
  cin >> n >> m >> k;
  for (lf = 1; lf < n; lf *= 2);
  for (int i = lf; i < n + lf; i++) {
    cin >> num[i];
  }
  init();

  int t = m + k;
  while (t--) {
    ll a, b, c;
    cin >> a >> b >> c;
    if (a == 1) {
      // b -> c
      update(b, c);
    } else {
      // b + c
      ll res = sum(b, c);
      cout << res << endl;
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