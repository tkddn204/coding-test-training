#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int sensor[10001];
int diff[10001];

void solve() {
  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    cin >> sensor[i];
  }

  sort(sensor, sensor + n);

  for (int i = 1; i < n; i++) {
    diff[i - 1] = sensor[i] - sensor[i - 1];
  }

  sort(diff, diff + n - 1);

  int res = 0;
  for (int i = 0; i < n - k; i++) {
    res += diff[i];
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