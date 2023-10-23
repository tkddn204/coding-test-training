#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int pascal[32][32];

void solve() {
  int n, k;
  cin >> n >> k;

  pascal[1][0] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < i; j++) {
      if (j == 0 || j == i - 1) pascal[i][j] = 1;
      else pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
    }
  }
  cout << pascal[n][k - 1];
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