#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n, m;
vector<pair<int,int>> graph[1001];
int dist[1001];

void solve() {
  cin >> n >> m;
  while(m--) {
    int a, b, c;
    cin >> a >> b >> c;
    graph[a].push_back({c, b});
  }
  int st, en;
  cin >> st >> en;

  fill (dist, dist + n + 1, (int)1e9);
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
  pq.push({0, st});
  dist[st] = 0;
  while (!pq.empty()) {
    auto [d, x] = pq.top(); pq.pop();

    if (d > dist[x]) continue;

    for (auto [nd, nx]: graph[x]) {
      nd += d;
      if (nd < dist[nx]) {
        dist[nx] = nd;
        pq.push({nd, nx});
      }
    }
  }
  cout << dist[en];
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