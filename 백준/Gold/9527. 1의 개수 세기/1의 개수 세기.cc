#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ull unsigned long long

ull arr[55];
ull a, b;

ull cal(ull n) {
  ull res = n & 1LL;

  for (int i = 54; i > 0; i--) {
    ull cur = (1LL << i);
    if (n & cur) {
      res += arr[i - 1] + (n - cur + 1);
      n -= cur;
    }
  }

  return res;
}

void solve() {
  cin >> a >> b;

  arr[0] = 1;
  for (int i = 1; i < 55; i++) {
    arr[i] = 2 * arr[i - 1] + (1LL << i);
  }
  cout << cal(b) - cal(a - 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  solve();
  return 0;
}