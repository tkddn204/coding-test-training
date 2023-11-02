#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n, r, g, gp;
vector<pair<int,int>> tree[200001];
int pillar, branch;

void findgiga(int pre, int k, int l) {  
  bool exist = tree[k].size() > 2 || (k == r && tree[k].size() == 2);
  bool same = (k != r && tree[k].size() == 1) || (k == r && tree[k].size() == 0);

  if (exist || same) {
    gp = pre;
    g = k;
    pillar = max(pillar, l);
    return;
  }

  for (auto [nxt, cost] : tree[k]) {
    if (nxt == pre) continue;
    findgiga(k, nxt, l + cost);
  }
}

void findleaf(int pre, int k, int l) {
  if (tree[k].size() < 2) {
    branch = max(branch, l);
    return;
  }

  for (auto [nxt, cost] : tree[k]) {
    if (pre == nxt) continue;
    findleaf(k, nxt, l + cost);
  }
}

void solve() {
  cin >> n >> r;

  for (int i = 1; i < n; i++) {
    int a, b, d;
    cin >> a >> b >> d;

    tree[a].push_back({b, d});
    tree[b].push_back({a, d});
  }

  findgiga(r, r, 0);
  findleaf(gp, g, 0);

  cout << pillar << ' ' << branch;
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