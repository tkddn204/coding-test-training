#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
  string s;
  cin >> s;

  set<char> sets;
  for (auto c : s) sets.insert(c);
  if (sets.size() == 1) {
    cout << -1;
    return;
  }

  bool pal = true;
  for (int i = 0; i < s.size() / 2; i++) {
    if (s[i] != s[s.size() - 1 - i]) {
      pal = false;
      break;
    }
  }
  if (pal) {
    cout << s.size() - 1;
    return;
  }

  cout << s.size();
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