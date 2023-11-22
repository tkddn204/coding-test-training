#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

int arr[500001];

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  sort(arr, arr + n);

  ll sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += abs(arr[i - 1] - i);
  }
  cout << sum;
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