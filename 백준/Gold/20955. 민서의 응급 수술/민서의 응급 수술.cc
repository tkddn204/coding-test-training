#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int parent[100001];
int chk[100001];

int find(int k) {
  if (k == parent[k]) return k;
  return parent[k] = find(parent[k]);
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
  for (int i = 1; i <= n; i++) parent[i] = i;

  int cnt = 0;

  while (m--) {
    int u, v;
    cin >> u >> v;
    if (find(u) != find(v)) uni(u, v);
    else cnt++;
  }

  for (int i = 2; i <= n; i++) {
    if (i == find(i)) cnt++;
  }
  cout << cnt;
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