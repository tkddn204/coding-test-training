#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int chk[33];

void solve() {
  string s;
  cin >> s;
  for (auto c: s) chk[c - 'A']++;
  
  int k = 0;
  for (int i = 0; i < 27; i++) {
    if (chk[i] == 0) continue;
    k += chk[i] % 2;
  }

  if (k >= 2) cout << "I'm Sorry Hansoo";
  else {
    string ans;
    string rest;
    for (int i = 0; i < 27; i++) {
      if (chk[i] == 0) continue;
      for (int j = 0; j < chk[i] / 2; j++) {
        ans += i + 'A';
      }
      if (chk[i] % 2 == 1) rest += i + 'A';
    }

    string right = ans;
    reverse(right.begin(), right.end());
    cout << ans << rest << right;
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