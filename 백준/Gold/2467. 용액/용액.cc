#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

int n;
ll arr[100001];

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];

  int st = 0, en = n - 1;
  ll minDiff = LLONG_MAX;
  int minSt, minEn;
  while (st < en) {
    ll diff = arr[st] + arr[en];
    if (minDiff > abs(diff)) {
      minDiff = abs(diff);
      minSt = arr[st];
      minEn = arr[en];
    }
    if (diff > 0) en--;
    else st++;
  }
  cout << minSt << ' ' << minEn;
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