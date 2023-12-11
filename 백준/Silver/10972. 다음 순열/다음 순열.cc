#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

int arr[10001];

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];

  int i = n - 1;
  while (i > 0 && arr[i - 1] >= arr[i]) i--;

  if (i == 0) {
    cout << -1;
    return;
  }

  int j = n - 1;
  while (j >= i && arr[j] <= arr[i - 1]) j--;
  swap(arr[i - 1], arr[j]);
  
  reverse(arr + i, arr + n);

  for (int i = 0; i < n; i++) {
    cout << arr[i] << ' ';
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