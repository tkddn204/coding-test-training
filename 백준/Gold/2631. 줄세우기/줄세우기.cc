#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int children[201];
int cnt[201];

void solve() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> children[i];
  }

  cnt[0] = 1;
  int maxCnt = 1;
  for (int i = 1; i < n; i++) {
    int m = 0;
    for (int j = 0; j < i; j++) {
      if (children[j] < children[i]) {
        m = max(m, cnt[j]);
      }
    }
    cnt[i] = m + 1;
    maxCnt = max(maxCnt, cnt[i]);
  }

  cout << n - maxCnt;

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