#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

struct edge {
  double dist;
  int x, y;
};

int parent[1001];
vector<pair<int,int>> god;
vector<edge> graph;

int find(int x) {
  if (x == parent[x]) return x;
  return parent[x] = find(parent[x]);
}

void uni(int a, int b) {
  a = find(a);
  b = find(b);
  
  if (a < b) parent[b] = a;
  else parent[a] = b; 
}

void solve() {
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= 1000; i++) parent[i] = i;

  god = vector<pair<int,int>>(n + 1);
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    god[i] = {x, y};
  }

  while (m--) {
    int x, y;
    cin >> x >> y;
    uni(x, y);
  }

  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= n; j++)  {
      double xd = god[i].first - god[j].first;
      xd *= xd;
      double yd = god[i].second - god[j].second;
      yd *= yd;
      graph.push_back({sqrt(xd + yd), i, j});
    }
  }

  sort(graph.begin(), graph.end(), [&](edge& a, edge& b) -> bool {
    return a.dist < b.dist;
  });

  double res = .0;
  for (auto [dist, i, j]: graph) {
    if (find(i) != find(j)) {
      uni(i, j);
      res += dist;
    }
  }

  cout << fixed << setprecision(2) << res;
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