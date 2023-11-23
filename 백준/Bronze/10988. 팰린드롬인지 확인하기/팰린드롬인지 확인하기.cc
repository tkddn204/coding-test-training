#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
  string s;
  cin >> s;
  for (int i = 0; i < s.size() / 2; i++) {
    if (s[i] != s[s.size() - 1 - i]) {
      cout << 0;
      return;
    }
  }
  cout << 1;
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