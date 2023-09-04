#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

string wrong[4] = {
  "1234567890-=",
  "WERTYUIOP[]\\",
  "SDFGHJKL;'",
  "XCVBNM,./"
};
string origin[4] = {
  "`1234567890-",
  "QWERTYUIOP[]",
  "ASDFGHJKL;",
  "ZXCVBNM,."
};
map<char,char> m;

void solve() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < wrong[i].size(); j++) {
      m[wrong[i][j]] = origin[i][j];
    }
  }
  m[' '] = ' ';

  string s;
  while (getline(cin, s)) {
    for (auto c : s) cout << m[c];
    cout << endl;
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