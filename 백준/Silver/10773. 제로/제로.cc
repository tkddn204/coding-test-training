#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int s[1000005], p;

void solve() {
  int k, n, r = 0;
  cin >> k;
  while (k--) {
    cin >> n;
    if (n == 0) {
      if (p > 0) s[p--] = 0;
    } else {
      s[++p] = n;
    }
  }
  for (int i = 1 ; i <= p ; ++i) {
    r += s[i];
  }
  cout << r;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  solve();
  return 0;
}