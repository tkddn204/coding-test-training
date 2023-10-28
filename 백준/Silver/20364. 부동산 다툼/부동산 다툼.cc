#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

void solve() {
  int n, q;
  cin >> n >> q;

  map<ll,bool> duck;
  while (q--) {
    ll k;
    cin >> k;

    ll cur = k, num = 0;
    while (cur) {
      if (duck[cur]) num = cur;
      cur /= 2;
    }

    if (num == 0) duck[k] = true;
    cout << num << endl;
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