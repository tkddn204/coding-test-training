#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

vector<pair<int,int>> meeting;

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n ; i++) {
    int a, b;
    cin >> a >> b;
    meeting.push_back({a, 1});
    meeting.push_back({b, -1});
  }
  sort(meeting.begin(), meeting.end());
  
  int cnt = 0;
  int res = 0;
  for (auto [t, v] : meeting) {
    res = max(res, cnt += v);
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