#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n, s, d;
vector<int> graph[100001];
int dist[100001];
int cnt;

int dfs(int cur, int parent) {
  for (auto nxt: graph[cur]) {
    if (nxt == parent) continue;
    dist[cur] = max(dist[cur], dfs(nxt, cur) + 1);
  }
  if (dist[cur] >= d && cur != s) cnt++;
  return dist[cur];
}

void solve() {
  cin >> n >> s >> d;

  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }

  dfs(s, -1);
  
  cout << cnt * 2;
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