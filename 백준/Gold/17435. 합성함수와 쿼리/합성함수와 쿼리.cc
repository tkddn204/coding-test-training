#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int f[200001][20];

void solve() {
  int m;
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> f[i][0];
  }
  
  for (int j = 1; j < 20; j++) {
    for (int i = 1; i <= m; i++) {
      f[i][j] = f[f[i][j - 1]][j - 1];
    }
  }
  
  int q;
  cin >> q;
  while (q--) {
    int n, x;
    cin >> n >> x;

    int j = 0;
    while (n > 0) {
      if (n & 1) x = f[x][j];
      n >>= 1;
      j++;
    }

    cout << x << endl;
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