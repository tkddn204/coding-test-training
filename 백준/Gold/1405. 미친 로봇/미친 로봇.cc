#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

typedef long double ld;

int n;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
double dp[4];
bool vst[30][30];
double ans = 0;

void dfs(int x, int y, double p, int cnt) {
    if (vst[x][y]) return;
    if (cnt == n) {
        ans += p;
        return;
    }
    
    vst[x][y] = true;
    for (int d = 0; d < 4; d++) {
      int nx = x + dx[d];
      int ny = y + dy[d];
      dfs(nx, ny, p * dp[d], cnt+1);
    }
    vst[x][y] = false;
}

void solve() {
  
  cin >> n;
  for (int i = 0; i < 4; i++) {
    int k;
    cin >> k;
    dp[i] = (double)k/100;
  }
  dfs(14, 14, 1, 0);
  
  cout << fixed;
  cout.precision(18);
  cout << ans;
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