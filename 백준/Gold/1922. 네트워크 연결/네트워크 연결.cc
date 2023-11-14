#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

struct edge {
  int c, a, b;
};
vector<edge> graph;
int parent[1001];

int find(int x) {
  if (parent[x] == x) return x;
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
  for (int i = 0; i <= n; i++) parent[i] = i;
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    graph.push_back({c, a, b});
  }
  sort(graph.begin(), graph.end(), [&](edge& a, edge& b) -> bool {
    return a.c < b.c;
  });

  int sum = 0;
  for (edge e : graph) {
    if (find(e.a) != find(e.b)) {
      uni(e.a, e.b);
      sum += e.c;
    }
  }
  cout << sum;
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