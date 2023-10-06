#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n;
int people[11];
int vst[11];

void dfs(int k) {
  if (k > n) {
    for (int i = 1; i <= n; i++) {
      int cnt = 0;
      for (int j = 1; j < i; j++) {
        cnt += vst[j] > vst[i];
      }
      if (cnt != people[vst[i]]) return;
    }
    for (int i = 1; i <= n; i++) {
      cout << vst[i] << ' ';
    }
    exit(0);
  }

  for (int i = 1; i <= n; i++) {
    if (vst[i]) continue;
    vst[i] = k;
    dfs(k + 1);
    vst[i] = 0;
  }
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> people[i];
  }

  dfs(1);
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