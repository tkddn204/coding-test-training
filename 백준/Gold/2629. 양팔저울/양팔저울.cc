#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n, m;
int chu[32];
int dp[32][15001];

void chk(int c, int w) {
  if (c > n || dp[c][w]) return;
  dp[c][w] = true;
  chk(c + 1, w + chu[c]);
  chk(c + 1, abs(w - chu[c]));
  chk(c + 1, w);
}

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> chu[i];
    m += chu[i];
  }
  chk(0, 0);

  int k;
  cin >> k;
  while (k--) {
    int w;
    cin >> w;
    if (w > m) cout << "N ";
    else if (dp[n][w]) cout << "Y ";
    else cout << "N ";
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