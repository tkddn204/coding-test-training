#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int nums[1000001];

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> nums[i];

  vector<int> dp;
  dp.push_back(nums[0]);
  for (int i = 1; i < n; i++) {
    if (dp.back() < nums[i]) dp.push_back(nums[i]);
    else *lower_bound(dp.begin(), dp.end(), nums[i]) = nums[i];
  }
  
  cout << dp.size();
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