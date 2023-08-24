#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

pair<int,int> tree[100001];
int vst[100001];
int rcnt;

void rtravel(int cur) {
  rcnt++;
  auto [lch, rch] = tree[cur];
  if (rch != -1) rtravel(rch);
}

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    tree[a] = {b, c};
  }
  rtravel(1);
  cout << (n - rcnt) * 2 + rcnt - 1;
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