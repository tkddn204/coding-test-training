#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

ll n, k;

int count(ll mid) {
  ll cnt = 0;
  for (int i = 1; i <= n; i++) {
    cnt += min(n, mid / i);
  }

  return cnt;
}

void solve() {
  cin >> n >> k;

  int st = 1;
  int en = k;

  while (st <= en) {
    int mid = (st + en) / 2;
    if (count(mid) >= k) en = mid - 1;
    else st = mid + 1;
  }

  cout << en + 1;
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