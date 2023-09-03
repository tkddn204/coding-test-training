#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define MOD 1000000007

int n, m, k;
ll num[1000001];
ll tree[4000004];

ll init(int node, int st, int en) {
  if (st == en) return tree[node] = num[st];
  int mid = (st + en) / 2;
  ll left = init(node * 2, st, mid);
  ll right = init(node * 2 + 1, mid + 1, en);
  return tree[node] = (left * right) % MOD;
}

void update(int node, int st, int en, int idx, ll val) {
  if (idx < st or idx > en) return;
  if (st == en) {
    tree[node] = val;
    return;
  }
  int mid = (st + en) / 2;
  update(node * 2, st, mid, idx, val);
  update(node * 2 + 1, mid + 1, en, idx, val);
  tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % MOD;
}

ll mul(int node, int st, int en, int from, int to) {
  if (to < st or from > en) return 1;
  if (from <= st and en <= to) return tree[node];
  int mid = (st + en) / 2;
  ll left = mul(node * 2, st, mid, from, to);
  ll right = mul(node * 2 + 1, mid + 1, en, from, to);
  return (left * right) % MOD;
}

void solve() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> num[i];
  }
  init(1, 1, n);

  int t = m + k;
  while (t--) {
    ll a, b, c;
    cin >> a >> b >> c;
    if (a == 1) {
      // b -> c
      update(1, 1, n, b, c);
    } else if (a == 2) {
      // b + c
      ll res = mul(1, 1, n, b, c);
      cout << res << endl;
    }
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