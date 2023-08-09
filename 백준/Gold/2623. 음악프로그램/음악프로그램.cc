#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n;
vector<int> order[1001];
int deg[1001];

void solve() {
  int n, m;
  cin >> n >> m;
  while (m--) {
    int k;
    cin >> k;
    int f;
    cin >> f;
    k--;
    while (k--) {
      int t;
      cin >> t;
      order[f].push_back(t);
      deg[t]++;
      f = t;
    }
  }

  queue<int> Q;
  for (int i = 1; i <= n; i++) {
    if (deg[i]) continue;
    Q.push(i);
  }
  vector<int> res;
  while (!Q.empty()) {
    int cur = Q.front(); Q.pop();
    res.push_back(cur);
    for (int nxt : order[cur]) {
      deg[nxt]--;
      if (deg[nxt]) continue;
      Q.push(nxt);
    }
  }
  if (res.size() == n) {
    for (auto e : res) cout << e << endl;
  } else {
    cout << 0 << endl;
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