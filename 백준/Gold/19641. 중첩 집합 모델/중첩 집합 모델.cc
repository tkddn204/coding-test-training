#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n;
vector<int> tree[100001];
pair<int,int> model[100001];
int vst[100001];

int dfs(int k, int left) {

  vst[k] = true;
  
  int right = left + 1;
  for (int nxt : tree[k]) {
    if (vst[nxt]) continue;
    right = dfs(nxt, right);
  }
  model[k] = {left, right};

  vst[k] = false;

  return right + 1;
}

void solve() {
  cin >> n;
  for (int i = 0; i < n ; i++) {
    int v;
    cin >> v;
    int k;
    while ((cin >> k) && k != -1) {
      tree[v].push_back(k);
    }
    sort(tree[v].begin(), tree[v].end());
  }
  int root;
  cin >> root;

  dfs(root, 1);

  for (int i = 1; i <= n; i++) {
    cout << i << ' ';
    cout << model[i].first << ' ' << model[i].second << endl;
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