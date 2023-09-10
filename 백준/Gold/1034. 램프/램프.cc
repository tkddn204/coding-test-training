#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

string lamp[51];

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> lamp[i];
  }

  int k;
  cin >> k;

  int res = 0;
  for (int i = 0; i < n; i++) {
    int zero = 0;
    for (int j = 0; j < m; j++) {
      if (lamp[i][j] == '0') zero++;
    }
    
    if (zero <= k and k % 2 == zero % 2) {
      int cnt = 0;
      for (int j = 0; j < n; j++) {
        if (lamp[i] == lamp[j]) cnt++;
      }
      res = max(res, cnt);   
    }
  }
  cout << res;
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