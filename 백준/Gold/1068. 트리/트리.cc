#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n, k;
int tree[51];
int cnt;

void remove(int root) {
  tree[root] = -1;
  vector<int> child;
  for (int i = 0; i < n; i++) {
    if (tree[i] == root) {
      child.push_back(i);
    }
  }

  for (int c : child) remove(c);
}

void leaf(int root) {
  vector<int> child;
  for (int i = 0; i < n; i++) {
    if (tree[i] == root) {
      child.push_back(i);
    }
  }

  if (child.empty()) {
    cnt++;
    return;
  }

  for (int c : child) leaf(c);
}

void solve() {
  cin >> n;
  fill(tree, tree + 51, -1);

  int root = -1;
  for (int i = 0; i < n; i++) {
    cin >> tree[i];
    if (tree[i] == -1) root = i;
  }
  cin >> k;

  if (k != root) {
    remove(k);
    leaf(root);
  }

  cout << cnt;
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