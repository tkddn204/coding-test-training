#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int parent[10001];
int cost[10001];
int a[10001];

int getp(int x) {
  if (parent[x] == x) return x;
  return parent[x] = getp(parent[x]);
}

void unionp(int a, int b) {
  a = getp(a);
  b = getp(b);
  if (a > b) parent[a] = b;
  else parent[b] = a;
}

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    parent[i] = i;
    cost[i] = INT_MAX;
  }
  while (m--) {
    int v, w;
    cin >> v >> w;
    unionp(v, w);
  }
  for (int i = 1; i <= n; i++) {
    int p = getp(i);
    cost[p] = min(cost[p], a[i]);
  }
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    if (cost[i] < INT_MAX) sum += cost[i];
  }
  if (sum > k) cout << "Oh no";
  else cout << sum;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  solve();
  return 0;
}