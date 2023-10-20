#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int graph[201][201];
int dist[201][201];

void solve() {
  int n, m;
  cin >> n >> m;
  
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) dist[i][j] = 0;
      else dist[i][j] = 1e9;
    }
  }

  for (int i = 0; i < m; i++) {
    int s, e, l;
    cin >> s >> e >> l;
    if (graph[s][e] < l) {
      graph[s][e] = l;
      graph[e][s] = l;
    }
    if (dist[s][e] > l) {
      dist[s][e] = l;
      dist[e][s] = l;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (dist[i][i] == 1e9) dist[i][i] = 0;
  }
  
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  double mintime = 1e9;
  
  for (int k = 1; k <= n; k++) {
    double maxtime = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (graph[i][j] == 0) continue;

        double rest = graph[i][j] - (dist[k][j] - dist[k][i]);

        if (rest > 0) {
          maxtime = max(maxtime, (rest / 2) + dist[k][j]);
        }
      }
    }
    mintime = min(mintime, maxtime);
  }

  cout << fixed << setprecision(1) << mintime;
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