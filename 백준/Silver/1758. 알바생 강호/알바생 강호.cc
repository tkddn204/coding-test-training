#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

ll tip[100001];

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> tip[i];
  sort(tip, tip + n, [&](int a, int b) -> bool {return a > b;});

  ll sum = 0;
  for (int i = 0; i < n; i++) {
    if (tip[i] - i < 0) break;
    sum += tip[i] - i;
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