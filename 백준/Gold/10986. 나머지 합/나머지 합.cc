#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

ll cnt[1001];

void solve() {
  int n, m;
  cin >> n >> m;

  ll sum = 0;
  while (n--) {
    int k;
    cin >> k;
    sum += k;
    cnt[sum % m]++;
  }

  ll res = cnt[0];
  for (int i = 0; i < m; i++) {
    res += cnt[i] * (cnt[i] - 1) / 2;
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