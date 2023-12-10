#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

bool chk(int n) {
  int c[10] = {};
  while (n) {
    c[n % 10]++;
    n /= 10;
  }
  for (int i = 0; i < 10; i++) {
    if (c[i] > 1) return false;
  }
  return true;
}

void solve() {
  int n, m;
  while (cin >> n) {
    cin >> m;

    int cnt = 0;
    for (int i = n; i <= m; i++) {
      cnt += chk(i);
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