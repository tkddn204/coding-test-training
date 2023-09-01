#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define X first

vector<tuple<int,int,int>> graph;
vector<pair<int,int>> sx, sy, sz;
int parent[100001];

int getParent(int x) {
  if (x == parent[x]) return x;
  return parent[x] = getParent(parent[x]);
}

void uniParent(int a, int b) {
  a = getParent(a);
  b = getParent(b);
  
  if (a != b) parent[b] = a;
}

bool cmp(pair<int,int>& a, pair<int,int>& b) {
  return a.X <= b.X;
}

void solve() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    parent[i] = i;
    int x, y, z;
    cin >> x >> y >> z;
    sx.push_back({x, i});
    sy.push_back({y, i});
    sz.push_back({z, i});
  }

  sort(sx.begin(), sx.end(), cmp);
  sort(sy.begin(), sy.end(), cmp);
  sort(sz.begin(), sz.end(), cmp);

  for (int i = 0; i < n - 1; i++) {
    auto [axx, axi] = sx[i];
    auto [bxx, bxi] = sx[i + 1];
    graph.push_back({abs(bxx - axx), axi, bxi});
    
    auto [ayx, ayi] = sy[i];
    auto [byx, byi] = sy[i + 1];
    graph.push_back({abs(byx - ayx), ayi, byi});
    
    auto [azx, azi] = sz[i];
    auto [bzx, bzi] = sz[i + 1];
    graph.push_back({abs(bzx - azx), azi, bzi});
  }

  sort(graph.begin(), graph.end());

  int mincost = 0;
  for (auto [c, a, b]: graph) {
    if (getParent(a) == getParent(b)) continue;
    uniParent(a, b);
    mincost += c;
  }
  cout << mincost;
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