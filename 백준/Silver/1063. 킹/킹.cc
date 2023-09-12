#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
  string kg, st;
  cin >> kg >> st;
  int n;
  cin >> n;
  while(n--) {
    string s;
    cin >> s;
    int nx = 0, ny = 0;
    for (char c: s) {
      if (c == 'R') nx++;
      else if (c == 'L') nx--;
      else if (c == 'B') ny--;
      else if (c == 'T') ny++;
    }
    char kgnx = kg[0] + nx;
    char kgny = kg[1] + ny;
    if (kgnx < 'A' || kgnx > 'H' || kgny < '1' || kgny > '8') continue;
    if (kgnx == st[0] and kgny == st[1]) {
      char stnx = st[0] + nx;
      char stny = st[1] + ny;
      if (stnx < 'A' || stnx > 'H' || stny < '1' || stny > '8') continue;
      st = stnx;
      st += stny;
    }
    kg = kgnx;
    kg += kgny;
  }
  cout << kg << endl;
  cout << st << endl;
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