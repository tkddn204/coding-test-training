#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int arr[100001];

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);

  int st = 0, en = n - 1;
  int res = INT_MAX;
  int a = 0, b = n - 1;
  while (st < en) {
    int val = arr[st] + arr[en];
    if (abs(val) < res) {
      res = abs(val);
      a = st; b = en;
    }

    if (val < 0) st++;
    else en--;
  }
  cout << arr[a] << ' ' << arr[b];
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