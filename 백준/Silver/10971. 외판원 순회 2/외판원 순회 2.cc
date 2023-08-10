#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n;
int w[11][11];
bool vst[11];
int minCost = INT_MAX;
int start;

void go(int a, int cost, int cnt) {
  if (cnt == n) {
    if (w[a][start] == 0) return;
    cost += w[a][start];
    minCost = min(minCost, cost);
    return;
  }

  for (int b = 0; b < n; b++) {
    if (vst[b] or w[a][b] == 0) continue;
    vst[b] = true;
    go(b, cost + w[a][b], cnt + 1);
    vst[b] = false;
  }
}

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int c;
      cin >> c;
      w[i][j] = c;
    }
  }
  
  for (int i = 0; i < n; i++) {
    fill(vst, vst + n, false);
    vst[i] = true;
    start = i;
    go(i, 0, 1);
  }
  cout << minCost;
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