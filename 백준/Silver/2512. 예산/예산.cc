#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n, m;
int arr[100001];

bool go(int mid) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += min(mid, arr[i]);
  }
  return sum <= m;
}

void solve() {
  cin >> n;
  int mx = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    mx = max(mx, arr[i]);
  }
  cin >> m;

  sort(arr, arr + n);

  int l = 0;
  int r = mx;
  int res = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (go(mid)) {
      res = mid;
      l = mid + 1;
    } else r = mid - 1;
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