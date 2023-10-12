#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  int b = s[0] == 'B';
  int r = s[0] == 'R';
  char pre = s[0];
  for (int i = 1; i < n; i++) {
    if (pre == s[i]) continue;
    else {
      pre = s[i];
      b += s[i] == 'B';
      r += s[i] == 'R';
    }
  }
  cout << (1 + (b > r ? r : b));
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