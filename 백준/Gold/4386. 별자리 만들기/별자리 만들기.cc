#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int parent[101];
pair<double,double> star[101];
vector<tuple<double, int, int>> graph;

int getParent(int x) {
  if (x == parent[x]) return x;
  return parent[x] = getParent(parent[x]);
}

void uniParent(int a, int b) {
  a = getParent(a);
  b = getParent(b);

  if (a != b) parent[b] = a;
}

void solve() {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    parent[i] = i;
    double x, y;
    cin >> x >> y;
    star[i] = {x, y};
  }

  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      auto [ax, ay] = star[i];
      auto [bx, by] = star[j];
      double d1 = bx - ax;
      double d2 = by - ay;
      double dis = sqrt((d1 * d1) + (d2 * d2));
      graph.push_back({dis, i, j});
    }
  }
  sort(graph.begin(), graph.end());

  double total = 0.;
  for (auto [dis, a, b]: graph) {
    if (getParent(a) == getParent(b)) continue;
    uniParent(a, b);
    total += dis;
  }
  cout << fixed << setprecision(2) << total;
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