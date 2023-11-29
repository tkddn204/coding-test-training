#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int arr[1001];

void solve() {
  int n, l;
  cin >> n >> l;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  sort(arr, arr + n);

  int st = arr[0];

  int tape = 1;
  for (int i = 1; i < n; i++) {
    if (l <= arr[i] - st) {
      tape++;
      st = arr[i];
    }
  }
  cout << tape;
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