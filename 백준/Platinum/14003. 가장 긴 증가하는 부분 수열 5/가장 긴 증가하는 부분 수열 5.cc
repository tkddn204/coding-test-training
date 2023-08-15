#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int nums[1000001];
int idx[1000001];

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> nums[i];

  vector<int> dp;
  dp.push_back(nums[0]);
  for (int i = 1; i < n; i++) {
    if (dp.back() < nums[i]) {
      dp.push_back(nums[i]);
      idx[i] = dp.size() - 1;
    } else {
      int it = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
      dp[it] = nums[i];
      idx[i] = it;
    }
  }

  cout << dp.size() << endl;

  vector<int> res;
  int residx = dp.size() - 1;
  for (int i = n - 1; i >= 0; i--) {
    if (idx[i] == residx) {
      res.push_back(nums[i]);
      residx--;
    }
  }

  reverse(res.begin(), res.end());
  for (auto e : res) cout << e << ' ';
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