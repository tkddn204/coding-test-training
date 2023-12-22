#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n, w;
pair<int,int> evt[1001];
int mnres = 1e9;
int res[1001];
int dp[1001][1001];
int memo[1001][1001];

int dist(pair<int,int> c, pair<int,int> e) {
  auto [ax, ay] = c;
  auto [bx, by] = e;
  return abs(ax - bx) + abs(ay - by);
}

int go(int a, int b) {
  if (a >= w || b >= w) return 0;
  if (dp[a][b]) return dp[a][b];

  int nxt = max(a, b) + 1;
  pair<int,int> acur = a == 0 ? make_pair(1, 1) : evt[a - 1];
  pair<int,int> bcur = b == 0 ? make_pair(n, n) : evt[b - 1];
  int ak = go(nxt, b) + dist(acur, evt[nxt - 1]);
  int bk = go(a, nxt) + dist(bcur, evt[nxt - 1]);

  memo[a][b] = (ak > bk) + 1;
  return dp[a][b] = min(ak, bk);
}

void solve() {
  cin >> n >> w;
  for (auto& [a, b]: evt) {
    cin >> a >> b;
  }

  cout << go(0, 0) << endl;

  int a = 0, b = 0;
  for (int k = 0; k < w; k++) {
    cout << memo[a][b] << endl;
    if (memo[a][b] == 1) a = k + 1;
    else b = k + 1;
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