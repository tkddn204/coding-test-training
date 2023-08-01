#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int arr[3];
int maxDP[2][4];
int minDP[2][4];

void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 3; j++) {
      cin >> arr[j];
      maxDP[0][j] = maxDP[1][j];
      minDP[0][j] = minDP[1][j];
    }
    
    maxDP[1][1] = max(maxDP[0][1] + arr[1], maxDP[0][2] + arr[1]);
    maxDP[1][2] = max(maxDP[0][1] + arr[2], max(maxDP[0][2] + arr[2], maxDP[0][3] + arr[2]));
    maxDP[1][3] = max(maxDP[0][2] + arr[3], maxDP[0][3] + arr[3]);

    minDP[1][1] = min(minDP[0][1] + arr[1], minDP[0][2] + arr[1]);
    minDP[1][2] = min(minDP[0][1] + arr[2], min(minDP[0][2] + arr[2], minDP[0][3] + arr[2]));
    minDP[1][3] = min(minDP[0][2] + arr[3], minDP[0][3] + arr[3]);
  }
  int maxVal = *max_element(maxDP[1] + 1, maxDP[1] + 4);
  int minVal = *min_element(minDP[1] + 1, minDP[1] + 4);

  cout << maxVal << ' ' << minVal;
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