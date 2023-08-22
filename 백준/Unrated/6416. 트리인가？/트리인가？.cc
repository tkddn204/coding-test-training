#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define U first
#define V second

vector<pair<int,int>> edge;
map<int, bool> vertex;
map<int, bool> vst;
map<int, int> deg;

bool isCycle(int root) {
  if (vst[root]) return true;
  vst[root] = true;
  for (auto [u, v] : edge) {
    if (u == root) {
      if (vst[v]) continue;
      isCycle(v);
    }
  }
  return false;
}

int findRoot() {
  int root = -1;
  for (auto [u, v]: vertex) {
    if (!v) continue;
    if (deg[u] > 1) return -1;
    else if (deg[u] == 0) {
      if (root == -1) root = u;
      else return -1;
    }
  }

  return root;
}

bool isTree() {
  if (edge.empty()) return true;

  int root = findRoot();
  if (root == -1) return false;

  vst.clear();
  if (isCycle(root)) return false;

  return true;
}

void solve() {
  int t = 1;
  while (true) {
    int u, v;
    cin >> u >> v;
    if (u < 0 and v < 0) break;
    if (u + v == 0) {
      cout << "Case " << t << " is " <<
          (!isTree() ? "not " : "") << "a tree." << endl;

      edge.clear();
      vertex.clear();
      deg.clear();
      t++;
    } else {
      edge.push_back({u, v});
      vertex[u] = true;
      vertex[v] = true;
      deg[v]++;
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