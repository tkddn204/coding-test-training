#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

pair<ll, ll> gift[100001];

bool cmp(pair<ll, ll>& a, pair<ll, ll>& b) {
  if (a.second == b.second) {
    return a.first < b.first;
  }
  return a.second < b.second;
}

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> gift[i].first;
  for (int i = 0; i < n; i++) cin >> gift[i].second;
  sort(gift, gift + n, cmp);

  ll res = 0;

  ll beforeMax = gift[0].second;
  ll curMax = 0;
  for (int i = 0; i < n; i++) {
    auto& [expire, use] = gift[i];

    if (beforeMax > expire) {
      beforeMax = max(beforeMax, use);
      
      int extend = (beforeMax - expire) / 30;
      extend += (beforeMax - expire) % 30 != 0;
      
      expire += extend * 30;
      res += extend;
    }

    curMax = max(curMax, expire);
    if (i < n - 1)
      if (gift[i].second < gift[i + 1].second) {
        beforeMax = curMax;
      }
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