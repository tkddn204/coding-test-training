#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int road[100001];
int price[100001];

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) cin >> road[i];
  for (int i = 0; i < n; i++) cin >> price[i];
  
  int cur = price[0];
  int sum = road[0] * cur;
  for (int i = 1; i < n; i++) {
    cur = min(cur, price[i]);
    sum += road[i] * cur;
  }
  cout << sum;
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