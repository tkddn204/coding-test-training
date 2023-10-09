#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n, m;
vector<pair<int,int>> graph[501];
vector<vector<int>> pre;
bool chk[501][501];

int dstra(int src, int des) {
  int dist[n];
  fill(dist, dist + n, 1e9);

  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
  pq.push({0, src});
  dist[src] = 0;
  while (!pq.empty()) {
    auto [cost, cur] = pq.top(); pq.pop();

    if (cost > dist[cur]) continue;

    for (auto [ncost, nxt] : graph[cur]) {
      if (chk[cur][nxt]) continue;
      int nxd = dist[cur] + ncost;
      if (nxd == dist[nxt]) {
        pre[nxt].push_back(cur);
      } else if (nxd < dist[nxt]) {
        pre[nxt].clear();
        pre[nxt].push_back(cur);
        dist[nxt] = nxd;
        pq.push({dist[nxt], nxt});
      }
    }
  }

  return dist[des] == 1e9 ? -1 : dist[des];
}

void dfs(int cur) {
  for (int from : pre[cur]) {
    if (chk[from][cur]) continue;
    chk[from][cur] = true;
    dfs(from);
  }
}

void solve() {
  while (true) {
    cin >> n >> m;
    if (n + m == 0) break;

    int s, d;
    cin >> s >> d;
    while (m--) {
      int u, v, p;
      cin >> u >> v >> p;
      graph[u].push_back({p, v});
    }
    
    pre = vector<vector<int>>(n);
    for (int i = 0; i < n; i++) {
      fill(chk[i], chk[i] + n, false);
    }

    int sh = dstra(s, d);
    if (sh > -1) {
      dfs(d);
      sh = dstra(s, d);
    }

    cout << sh << endl;

    for (int i = 0; i < n; i++) {
      graph[i].clear();
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