#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n, k, c;
int cut[10001];

int go(int m) {
  if (n - cut[k - 1] > m) return 0;

  int res = n;
  int cnt = 0;

  int p = k - 1;
  while (p-- && cnt < c) {
    if (res - cut[p] > m) {
      res = cut[p + 1];
      if (res - cut[p] > m) return 0;
      cnt++;
    }
  }
  if (cnt < c) res = cut[0];
  if (res > m) return 0;
  return res;
}

void solve() {
  cin >> n >> k >> c;
  for (int i = 0; i < k; i++) cin >> cut[i];
  sort(cut, cut + k);
  
  int l = 0;
  int r = n;
  int p = 0;
  while (l < r) {
    int m = (l + r) / 2;
    int chk = go(m);
    if (!chk) l = m + 1;
    else r = m, p = chk;
  }
  cout << r << ' ' << p;
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