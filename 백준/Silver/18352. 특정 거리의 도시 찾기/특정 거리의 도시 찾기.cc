#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

vector<int> graph[300001];
int dis[300001];

void solve() {
  int n, m, k, x;
  cin >> n >> m >> k >> x;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
  }

  fill(dis, dis + n + 1, 1e9);
  queue<int> Q;
  Q.push(x);
  dis[x] = 0;
  while (!Q.empty()) {
    int cur = Q.front(); Q.pop();

    for (int nxt: graph[cur]) {
      if (dis[nxt] < dis[cur] + 1) continue;
      dis[nxt] = min(dis[nxt], dis[cur] + 1);
      Q.push(nxt);
    }
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (dis[i] < 1e9 and dis[i] == k) {
      cout << i << endl;
      cnt++;
    }
  }
  if (cnt == 0) cout << -1;
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