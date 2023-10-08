#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

string a, b;

void solve() {
  cin >> a >> b;
  int asize = a.size();
  int bsize = b.size();

  if (asize == bsize) {
    int cnt = 0;
    for (int i = 0; i < asize; i++) {
      cnt += a[i] != b[i];
    }
    cout << cnt;
    return;
  }

  int maxcnt = 0, maxidx = 0;
  for (int i = 0; i <= bsize - asize; i++) {
    int cnt = 0;
    for (int j = 0; j < asize; j++) {
      if (b[i + j] == a[j]) cnt++;
    }
    maxcnt = max(maxcnt, cnt);
  }
  cout << asize - maxcnt;
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