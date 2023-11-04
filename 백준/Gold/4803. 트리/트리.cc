#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

vector<vector<int>> tree;
bool vst[501];

bool dfs(int parent, int cur) {
  vst[cur] = true;
  for (int nxt : tree[cur]) {
    if (nxt == parent) continue;
    if (vst[nxt]) return false;
    if (!dfs(cur, nxt)) return false;
  }
  return true;
}

void solve() {
  for (int t = 1;;t++) {
    int n, m;
    cin >> n >> m;
    if (n + m == 0) break;

    tree = vector<vector<int>>(n + 1);
    while(m--) {
      int a, b;
      cin >> a >> b;
      tree[a].push_back(b);
      tree[b].push_back(a);
    }
    
    int res = 0;
    fill(vst, vst + n + 1, 0);
    for (int i = 1; i <= n; i++) {
      if (vst[i]) continue;
      res += dfs(i, i);
    }

    cout << "Case " << t << ": ";
    if (res > 1) {
      cout << "A forest of " << res << " trees." << endl;
    } else if (res == 1) {
      cout << "There is one tree." << endl;
    } else {
      cout << "No trees." << endl;
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