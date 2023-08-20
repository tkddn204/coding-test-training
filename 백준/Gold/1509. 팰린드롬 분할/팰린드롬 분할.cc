#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

string s;
int dp[2501][2501];
int cnt[2501];

bool isPal(int st, int en) {
  if (st >= en) return true;
  if (dp[st][en] != -1) return dp[st][en];
  if (s[st] != s[en]) return dp[st][en] = false;
  return dp[st][en] = isPal(st + 1, en - 1);
}

void solve() {
  cin >> s;
  int n = s.size();
  s = " " + s;

  for (int i = 1; i <= n; i++) {
    fill(dp[i], dp[i] + n + 1, -1);
  }
  fill(cnt, cnt + n + 1, 1e9);

  cnt[0] = 0;
  for (int i = 1; i <= n; i++) {
    cnt[i] = cnt[i - 1] + 1;
    for (int j = 1; j <= i; j++) {
      if (!isPal(j, i)) continue;
      cnt[i] = min(cnt[i], cnt[j - 1] + 1);
    }
  }

  cout << cnt[n];
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