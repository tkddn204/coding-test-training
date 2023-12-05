#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

pair<ll, ll> town[100001];

void solve() {
  int n;
  cin >> n;
  
  ll sum = 0;
  for (int i = 0 ; i < n; i++) {
    cin >> town[i].first >> town[i].second;
    sum += town[i].second;
  }
  sort(town, town + n);

  ll cur = 0;
  for (int i = 0; i < n; i++) {
    cur += town[i].second;
    if (cur >= (sum + 1) / 2) {
      cout << town[i].first;
      break;
    }
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