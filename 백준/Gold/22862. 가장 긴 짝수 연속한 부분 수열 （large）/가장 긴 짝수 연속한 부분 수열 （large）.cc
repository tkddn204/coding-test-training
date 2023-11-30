#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int arr[1000001];

void solve() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> arr[i];

  int st = 0, en = 1;
  int cnt = arr[0] % 2 == 1;
  int res = 0;

  for (int st = 0; st < n;  st++) {
    while (en < n) {
      if (arr[en] % 2) {
        if (cnt >= k) break;
        cnt++;
      }
      en++;
    }
    if (en > n) break;
    res = max(res, en - st - cnt);
    if (arr[st] % 2) cnt--;
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