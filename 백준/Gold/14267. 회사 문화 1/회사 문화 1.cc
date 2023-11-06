#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

vector<int> children[100001];
int praise[100001];

void dfs(int cur) {
  for (int nxt : children[cur]) {
    praise[nxt] += praise[cur];
    dfs(nxt);
  }
}

void solve() {
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    int p;
    cin >> p;
    if (p == -1) continue;
    children[p].push_back(i);
  }

  while (m--) {
    int i, w;
    cin >> i >> w;
    praise[i] += w;
  }

  dfs(1);

  for (int i = 1; i <= n; i++) {
    cout << praise[i] << ' ';
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