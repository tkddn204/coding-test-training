#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

vector<int> graph[32001];
int deg[32001];

void solve() {
  int n, m;
  cin >> n >> m;
  while(m--) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    deg[b]++;
  }

  priority_queue<int, vector<int>, greater<>> pq;
  for (int i = 1; i <= n; i++) {
    if (deg[i]) continue;
    pq.push(i);
  }

  while(!pq.empty()) {
    int cur = pq.top(); pq.pop();

    cout << cur << ' '; 
    for (auto e : graph[cur]) {
      deg[e]--;
      if (deg[e]) continue;
      pq.push(e);
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