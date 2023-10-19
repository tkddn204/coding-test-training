#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
  string a, b;
  cin >> a >> b;

  while (!b.empty()) {
    if (a == b) {
      cout << 1;
      return;
    }

    char back = b.back();
    b.erase(b.end() - 1);
    if (back == 'B') {
      reverse(b.begin(), b.end());
    }
  }
  cout << 0;
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