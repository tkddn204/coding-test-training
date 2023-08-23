#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

vector<int> tree[100001];

void solve() {
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }

  int q;
  cin >> q;
  while (q--) {
    int t, k;
    cin >> t >> k;
    if (t == 1) {
      if (tree[k].size() > 1) cout << "yes" << endl;
      else cout << "no" << endl;
    } else {
      cout << "yes" << endl;
    }
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