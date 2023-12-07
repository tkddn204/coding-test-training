#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

int stone[51];

void solve() {
  int m;
  cin >> m;
  int sum = 0;
  for (int i = 0; i < m; i++) {
    cin >> stone[i];
    sum += stone[i];
  }
  int k;
  cin >> k;

  double res = 0.;
  for (int i = 0; i < m; i++) {
    if (stone[i] < k) continue;
    double t = 1.0;
    for (int j = 0; j < k; j++) {
      t *= (double) (stone[i] - j) / (sum - j);
    }
    res += t;
  }

  cout << fixed << setprecision(9) << res;
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