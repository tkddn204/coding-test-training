#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
  int n;
  cin >> n;

  priority_queue<int, vector<int>, greater<>> pq;
  for (int i = 0; i < n*n; i++) {
    int k;
    cin >> k;
    pq.push(k);
    if (pq.size() > n) pq.pop();
  }
  cout << pq.top();
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