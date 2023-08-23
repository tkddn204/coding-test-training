#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

int n;
pair<int,int> tree[200001];
int root[200001];
int res;

void dfs(int rt, ll num) {
  if (res) return;
  auto [l, r] = tree[rt];

  if (l == -1 and r == -1) {
    res = rt;
    return;
  }

  if (l == -1) dfs(r, num);
  else if (r == -1) dfs(l, num);
  else {
    if (num % 2) dfs(l, num / 2 + 1);
    else dfs(r, num / 2);
  }
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int u, v;
    cin >> u >> v;
    tree[i] = {u, v};
    if (u != -1) root[u] = i;
    if (v != -1) root[v] = i;
  }

  ll k;
  cin >> k;
  dfs(1, k);

  cout << res;
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