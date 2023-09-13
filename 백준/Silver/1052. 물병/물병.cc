#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
void solve() {
  ll n, k;
  cin >> n >> k;

  if (n <= k) {
    cout << 0;
    return;
  }

  int res = 0;
  while (true) {
    int cnt = 0;
    int tmp = n++;
    while (tmp > 0) {
      if (tmp % 2 == 1) cnt++;
      tmp /= 2;
    }
    if (cnt <= k) break;
    res++;
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