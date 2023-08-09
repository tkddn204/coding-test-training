#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n;
vector<int> graph[1001];
int d[1001];
int dp[1001];
int deg[1001];

void solve() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      graph[i].clear();
    }
    fill(deg, deg + n + 1, 0);
    for (int i = 1; i <= n; i++) {
      cin >> d[i];
      dp[i] = d[i];
    }
    for (int i = 0; i < k; i++) {
      int x, y;
      cin >> x >> y;
      graph[x].push_back(y);
      deg[y]++;
    }
    int w;
    cin >> w;

    queue<int> Q;
    for (int i = 1; i <= n; i++) {
      if (deg[i]) continue;
      Q.push(i);
    }

    while (!Q.empty()) {
      int cur = Q.front(); Q.pop();
      
      for (int nxt: graph[cur]) {
        dp[nxt] = max(dp[nxt], dp[cur] + d[nxt]);
        deg[nxt]--;
        if (deg[nxt]) continue;
        Q.push(nxt);
      }
    }
    cout << dp[w] << endl;
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