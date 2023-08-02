#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
  string n;
  while (true) {
    string res = "yes";
    cin >> n;
    if (n == "0") break;
    int size = n.size();
    for (int i = 0 ; i < (size + 1) / 2 ; i++) {
      if (n[i] != n[size - i - 1]) res = "no";
    }
    cout << res << endl;
  }
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