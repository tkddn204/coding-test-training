#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

ll sol[5001];
ll minDiff = LLONG_MAX;
tuple<int,int,int> minIdx;

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> sol[i];
  
  sort(sol, sol + n);

  for (int i = 0; i < n - 2; i++) {
    int st = i + 1;
    int en = n - 1;
    while (st < en) {
      ll sum = sol[i] + sol[st] + sol[en];
      if (abs(sum) < minDiff) {
        minDiff = abs(sum);
        minIdx = {i, st, en};
      }
      if (sum < 0) st++;
      else en--;
    }
  }
  
  auto [a, b, c] = minIdx;
  cout << sol[a] << ' ' << sol[b] << ' ' << sol[c];
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