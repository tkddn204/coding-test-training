#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int arr[1000001];
int dp[1000001];

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  
  vector<int> seq;
  seq.push_back(arr[0]);
  dp[0] = 1;
  for (int i = 1; i < n; i++) {
    if (seq.back() < arr[i]) {
      seq.push_back(arr[i]);
      dp[i] = seq.size() - 1;
    } else {
      int st = 0;
      int en = seq.size() - 1;
      while (st < en) {
        int mid = (st + en) / 2;
        if (arr[i] > seq[mid]) st = mid + 1;
        else en = mid;
      }
      dp[i] = en;
      seq[en] = arr[i];
    }
  }
  cout << seq.size();
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