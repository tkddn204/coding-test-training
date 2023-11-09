#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

vector<pair<int,int>> graph[10001];
bool vst[10001];
int maxdist;

void dfs(int cur, int dist) {
  maxdist = max(maxdist, dist);
  vst[cur] = true;
  for (auto [nxt, d] : graph[cur]) {
    if (vst[nxt]) continue;
    dfs(nxt, dist + d);
  }
}

void solve() {
  int a, b, c;
  while (cin >> a) {
    cin >> b >> c;
    graph[a].push_back({b, c});
    graph[b].push_back({a, c});
  }
  for (int i = 0; i < 10001; i++) {
    fill(vst, vst + 10001, false);
    dfs(i, 0);
  }
  cout << maxdist;
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