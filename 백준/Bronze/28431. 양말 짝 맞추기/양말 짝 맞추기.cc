#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
  int a,b,c,d,e;
  cin>>a>>b>>c>>d>>e;
  cout<<(a^b^c^d^e);
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