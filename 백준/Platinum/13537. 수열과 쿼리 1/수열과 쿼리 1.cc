#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n;
int l, r, k;
vector<int> seg[4 * 100001];

void update(int i, int val, int node, int st, int en) {
  seg[node].push_back(val);
  
  if (st >= en) return;
  int mid = (st + en) / 2;

  if (i <= mid) update(i, val, node * 2, st, mid);
  else update(i, val, node * 2 + 1, mid + 1, en);
}

int query(int node, int st, int en) {
  if (l > en or r < st) return 0;
  if (l <= st and en <= r)
    return seg[node].end() - upper_bound(seg[node].begin(), seg[node].end(), k);
  int mid = (st + en) / 2;
  return query(node * 2, st, mid) + query(node * 2 + 1, mid + 1, en);
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int e;
    cin >> e;
    update(i, e, 1, 1, n);
  }
  
  for (int i = 1; i < 4 * n; i++) {
    sort(seg[i].begin(), seg[i].end());
  }

  int m;
  cin >> m;
  while (m--) {
    cin >> l >> r >> k;
    cout << query(1, 1, n) << endl;
  }
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