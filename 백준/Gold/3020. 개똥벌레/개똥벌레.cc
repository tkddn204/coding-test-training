#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n, h;
int cave[500001][2];
map<int,int> num;

void solve() {
  cin >> n >> h;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (i % 2 == 0) cave[x][0]++;
    else cave[h - x + 1][1]++;
  }

  for (int i = 1; i <= h; i++) {
    cave[h - i][0] += cave[h - (i - 1)][0];
    cave[i][1] += cave[i - 1][1];
  }

  int minVal = 1e9;
  for(int i = 1; i <= h; i++) {
    int c = cave[i][0] + cave[i][1];
    num[c]++;
    minVal = min(minVal, c);
  }

  cout << minVal << ' ' << num[minVal];
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