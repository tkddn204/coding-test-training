#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n, i, j, k;
vector<int> seg[4 * 100001];

void update(int i, int val, int node, int st, int en) {
  seg[node].push_back(val);

  if (st >= en) return;
  int mid = (st + en) / 2;
  if (i <= mid) update(i, val, node * 2, st, mid);
  else update(i, val, node * 2 + 1, mid + 1, en);
}

int query(int node, int st, int en) {
  if (i > en or j < st) return 0;
  if (i <= st and en <= j) {
    return seg[node].end() 
              - upper_bound(seg[node].begin(), seg[node].end(), k);
  }
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
  
  int m, ans = 0;
  cin >> m;
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    i = a^ans;
    j = b^ans;
    k = c^ans;
    ans = query(1, 1, n);
    cout << ans << endl;
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