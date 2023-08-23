#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

vector<pair<int,int>> cost[1001];
int vst[1001];
int res;

void dfs(int a, int b, int sum) {
  vst[a] = true;
  if (a == b) {
    res = sum;
    return;
  }

  for (auto [c, nxt]: cost[a]) {
    if (vst[nxt]) continue;
    dfs(nxt, b, sum + c);
  }
}

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    cost[a].push_back({c, b});
    cost[b].push_back({c, a});
  }
  for (int i = 0; i < 1001; i++) {
    sort(cost[i].begin(), cost[i].end());
  }

  while (m--) {
    int a, b;
    cin >> a >> b;
    fill(vst, vst + 1001, false);
    dfs(a, b, 0);
    cout << res << endl;
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