#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int student[100001];
int vst[100001];
int start[100001];

int getParent(int x, int p, int cnt) {
  if (vst[x]) {
    if (start[x] != p) return 0;
    return cnt - vst[x];
  }
  start[x] = p;
  vst[x] = cnt;
  return getParent(student[x], p, cnt + 1);
}

void solve() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    fill(vst, vst+n+1, 0);
    fill(start, start+n+1, 0);
    for (int i = 1; i <= n; i++) cin >> student[i];
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (vst[i]) continue;
      cnt += getParent(i, i, 1);
    }
    cout << n - cnt << endl;
  }
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