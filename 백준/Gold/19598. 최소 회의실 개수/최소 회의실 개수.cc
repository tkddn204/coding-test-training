#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

vector<pair<int, int>> arr;
priority_queue<int, vector<int>, greater<>> pq;

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int s, t;
    cin >> s >> t;
    arr.push_back({s, t});
  }
  sort(arr.begin(), arr.end());
  
  auto [a, b] = arr[0];
  pq.push(b);
  for (int i = 1; i < n; i++) {
    auto [a, b] = arr[i];
    if (pq.top() <= a) pq.pop();
    pq.push(b);
  }
  cout << pq.size();
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