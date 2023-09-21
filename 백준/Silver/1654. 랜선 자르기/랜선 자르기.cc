#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

int k, n;
int arr[10001];

bool isBig(ll x) {
  ll c = 0;
  for (int i = 0 ; i < k; i++) {
    c += arr[i] / x;
  }
  return c >= n;
}

void solve() {
  cin >> k >> n;
  for (int i = 0 ; i < k; i++) cin >> arr[i];
  ll st = 1;
  ll en = INT_MAX;
  while (st < en) {
    ll mid = (st+en+1) / 2;
    if (isBig(mid)) st = mid;
    else en = mid - 1;
  }
  cout << st;
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