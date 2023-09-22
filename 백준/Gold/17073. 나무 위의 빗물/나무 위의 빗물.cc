#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

vector<int> tree[500001];
int leaf;
bool vst[500001];

void solve() {
  int n, w;
  cin >> n >> w;

  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }

  for (int i = 2; i <= n; i++) {
    if (tree[i].size() == 1) leaf++;
  }

  double res = (double)w / leaf;
  cout << setprecision(10) << fixed << res;
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