#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

struct road {
  int x, y, z;
};

int parent[200001];

int find(int x) {
  if (x == parent[x]) return x;
  return parent[x] = find(parent[x]);
}

void uni(int a, int b) {
  a = find(a);
  b = find(b);
  
  if (a != b) parent[a] = b;
}

void solve() {
  while (true) {
    int m, n;
    cin >> m >> n;
    if (m + n == 0) break;

    vector<road> graph;
    for (int i = 0; i <= 200000; i++) parent[i] = i;

    int x, y, z;
    ll sum = 0;
    while (n--) {
      cin >> x >> y >> z;
      graph.push_back({x, y, z});
      sum += z;
    }
    sort(graph.begin(), graph.end(), [&](auto& a, auto& b) -> bool {
      return a.z < b.z;
    });

    ll cost = 0;
    for (road r : graph) {
      if (find(r.x) == find(r.y)) continue;
      uni(r.x, r.y);
      cost += r.z;
    }
    cout << sum - cost << endl;
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