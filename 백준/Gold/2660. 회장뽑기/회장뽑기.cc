#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

vector<int> friends[51];
int graph[51][51];

void solve() {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    fill(graph[i], graph[i] + n + 1, 1e9);
    graph[i][i] = 0;
  }

  while (true) {
    int a, b;
    cin >> a >> b;
    if (a == -1 and b == -1) break;
    graph[a][b] = graph[b][a] = 1;
  }


  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
      }
    }
  }

  vector<int> candidates[51];
  for (int i = 1; i <= n; i++) {
    int mx = 0;
    for (int j = 1; j <= n; j++) {
      mx = max(mx, graph[i][j]);
    }
    candidates[mx].push_back(i);
  }

  for (int i = 1; i <= n; i++) {
    if (candidates[i].empty()) continue;
    cout << i << ' ' << candidates[i].size() << endl;
    for (int can: candidates[i]) {
      cout << can << ' ';
    }
    break;
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