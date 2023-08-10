#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

vector<tuple<int,int,int>> graph;
int parent[100001];

int getParent(int x) {
  if (parent[x] == x) return x;
  return parent[x] = getParent(parent[x]);
}

void uniParent(int a, int b) {
  a = getParent(a);
  b = getParent(b);
  if (a != b) parent[b] = a;
}

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) parent[i] = i;
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    graph.push_back({c,a,b});
  }
  sort(graph.begin(), graph.end());

  int sum = 0, cur = 0;
  for (auto [c, a, b] : graph) {
    if (getParent(a) != getParent(b)) {
      sum += (cur = c);
      uniParent(a, b);
    }
  }
  sum -= cur;
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