#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define MOD 1000000007

ll inverse(ll a, ll b) {
  if (b == 1) return a;
  ll nb = b % 2 == 0 ? b / 2 : b - 1;
  ll p = inverse(a, nb) % MOD;
  return (b % 2 == 0 ? p : a) * p % MOD;
}

ll gcd(ll a, ll b) {
  return b ? gcd(b, a % b) : a;
}

void solve() {
  int m;
  cin >> m;

  ll sum = 0;
  while (m--) {
    ll n, s;
    cin >> n >> s;
    ll g = gcd(n, s);
    ll a = s / g;
    ll b = inverse((n / g), MOD - 2) % MOD;
    sum = (sum + a * b) % MOD;
  }

  cout << sum;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  solve();
  return 0;
}