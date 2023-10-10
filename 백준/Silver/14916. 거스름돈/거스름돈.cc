#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
  int n;
  cin >> n;
  if (n == 1 || n == 3) cout << -1;
  else if (n % 5) {
    if ((n % 5) % 2) {
      int k = (n / 5) - 1;
      cout << k + ((n - k * 5) / 2) << endl;
    } else cout << ((n / 5) + ((n % 5) / 2)) << endl;
  } else cout << (n / 5);
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