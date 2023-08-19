#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define X first
#define Y second

pair<ll,ll> point[4];

int ccwFunc(pair<ll,ll> p1, pair<ll,ll> p2, pair<ll,ll> p3) {
  ll a = (p1.X * p2.Y) + (p2.X * p3.Y) + (p3.X * p1.Y);
  ll b = (p1.X * p3.Y) + (p2.X * p1.Y) + (p3.X * p2.Y);
  return a > b ? 1 : a == b ? 0 : -1;
}

bool isCross() {
  int ccw[4];
  int ccwIdx[4][3] = {
    {0, 1, 2},
    {0, 1, 3},
    {2, 3, 0},
    {2, 3, 1}  
  };
  for (int i = 0; i < 4; i++) {
    ccw[i] = ccwFunc(point[ccwIdx[i][0]], point[ccwIdx[i][1]], point[ccwIdx[i][2]]);
  }

  return ccw[0] * ccw[1] < 0 and ccw[2] * ccw[3] < 0;
}

void solve() {
  for (auto& [x, y]: point) {
    cin >> x >> y;
  }
  cout << isCross();
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