#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define MOD 1000000007

int mp[8][8] = {
  {0, 1, 1, 0, 0, 0, 0, 0},
  {1, 0, 1, 1, 0, 0, 0, 0},
  {1, 1, 0, 1, 1, 0, 0, 0},
  {0, 1, 1, 0, 1, 1, 0, 0},
  {0, 0, 1, 1, 0, 1, 0, 1},
  {0, 0, 0, 1, 1, 0, 1, 0},
  {0, 0, 0, 0, 0, 1, 0, 1},
  {0, 0, 0, 0, 1, 0, 1, 0}
};

vvll operator*(vvll& a, vvll& b) {
  vvll tmp(8, vll(8, 0));

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      for (int k = 0; k < 8; k++) {
        tmp[i][j] += a[i][k] * b[k][j];
        tmp[i][j] %= MOD;
      }
    }
  }

  return tmp;
}

void solve() {
  ll d;
  cin >> d;

  vvll res(8, vll(8, 0));
  vvll mul(8, vll(8, 0));
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (i == j) res[i][j] = 1;
      mul[i][j] = mp[i][j];
    }
  }

  while (d) {
    if (d % 2 == 1) {
      res = res * mul;
      d -= 1;
    }
    mul = mul * mul;
    d /= 2;
  }
  cout << res[0][0];
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