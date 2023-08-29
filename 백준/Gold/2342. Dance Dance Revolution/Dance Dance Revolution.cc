#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

vector<int> arr;
int dp[100001][5][5];
int power[5][5] = {
  {1, 2, 2, 2, 2},
  {0, 1, 3, 4, 3},
  {0, 3, 1, 3, 4},
  {0, 4, 3, 1, 3},
  {0, 3, 4, 3, 1}
};

int rec(int k, int l, int r) {
  if (k == arr.size()) return 0;
  if (l == r and l != 0) return 1e9;
  if (dp[k][l][r]) return dp[k][l][r];

  int nxt = arr[k + 1];
  dp[k][l][r] =
      min(rec(k + 1, nxt, r) + power[l][nxt],
            rec(k + 1, l, nxt) + power[r][nxt]);

  return dp[k][l][r];
}

void solve() {
  arr.push_back(0);
  while (true) {
    int k;
    cin >> k;
    if (k == 0) break;
    arr.push_back(k);
  }

  cout << rec(0, 0, 0);
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