#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
  int n, s, p;
  cin >> n >> s >> p;

  priority_queue<int> pq;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    pq.push(k);
  }

  int cnt = 0, res = 1;
  for (int i = 0; i < n; i++) {
    int t = pq.top(); pq.pop();
    if (t > s) res++;
    else if (t < s) break;
    cnt++;
  }
  if (cnt >= p) res = -1;
  if (n == 0) res = 1;
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