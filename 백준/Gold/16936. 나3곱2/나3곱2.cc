#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

int n;
map<ll, int> B;
vector<ll> arr;

void dfs(ll cur, int k) {
  if (k == n) {
    for (ll a: arr) {
      cout << a << ' ';
    }
    exit(0);
  }
  ll nxt = cur / 3;
  if (cur % 3 == 0 && B[nxt]) {
    arr.push_back(nxt);
    B[nxt]--;
    dfs(nxt, k + 1);
    arr.pop_back();
    B[nxt]++;
  }
  nxt = cur * 2;
  if (B[nxt]) {
    arr.push_back(nxt);
    B[nxt]--;
    dfs(nxt, k + 1);
    arr.pop_back();
    B[nxt]++;
  }
}

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    ll b;
    cin >> b;
    B[b]++;
  }

  for (auto [k, v] : B) {
    arr.push_back(k);
    dfs(k, 1);
    arr.pop_back();
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