#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n, k;
int t[11][11];
bool vst[11];
int sum = 1e9;

void go(int c, int k, int s) {
  if (k == n) {
    sum = min(sum, s);
    return;
  }

  for (int i = 0; i < n; i++) {
    if (vst[i]) continue;
    vst[i] = true;
    go(i, k + 1, s + t[c][i]);
    vst[i] = false;
  }
}

void solve() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> t[i][j];
    }
  }

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        t[i][j] = min(t[i][j], t[i][k] + t[k][j]);
      }
    }
  }

  vst[k] = true;
  go(k, 1, 0);
  
  cout << sum;
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