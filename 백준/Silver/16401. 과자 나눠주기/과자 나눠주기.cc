#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int m, n;
int sum;
int arr[1000001];

bool go(int len) {
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cnt += arr[i] / len;
  }
  return cnt >= m;
}

void solve() {
  cin >> m >> n;
  int mx = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    mx = max(mx, arr[i]);
  }
  sort(arr, arr + n);

  int l = 1, r = mx, res = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (go(mid)) res = mid, l = mid + 1;
    else r = mid - 1;
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