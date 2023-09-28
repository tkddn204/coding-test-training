#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int arr[501];

void solve() {
  int h, w;
  cin >> h >> w;

  for (int i = 0; i < w; i++) {
    cin >> arr[i];
  }
  
  int water = 0;
  for (int i = 1; i < w; i++) {
    int left = *max_element(arr, arr + i);
    int right = *max_element(arr + i + 1, arr + w);
    int cur = arr[i];
    if (cur < left && cur < right) {
      water += min(left, right) - cur;
    }
  }

  cout << water;
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