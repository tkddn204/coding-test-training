#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n, m, k;
string s[2001];
int chess[2002][2002];

int go(char c) {
  for (int i = 0; i <= n; i++) {
    fill(chess[i], chess[i] + m + 1, 0);
  }

  int nxt;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if ((i + j) % 2) nxt = s[i][j] == c;
      else nxt = s[i][j] != c;
      
      chess[i + 1][j + 1] = chess[i + 1][j] + chess[i][j + 1] - chess[i][j] + nxt;
    }
  }
  
  int res = 1e9;
  for (int i = 0; i <= n - k; i++) {
    for (int j = 0; j <= m - k; j++) {
      res = min(res, chess[i + k][j + k] - chess[i + k][j] - chess[i][j + k] + chess[i][j]);
    }
  }
  
  return res;
}

void solve() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }

  if (k == 1) {
    cout << 0;
    return;
  }
  
  cout << min(go('B'), go('W'));
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