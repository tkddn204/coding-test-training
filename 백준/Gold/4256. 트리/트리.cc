#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int preorder[1001];
int inorder[1001];

void post(int st, int en, int root) {
  for (int i = st; i < en; i++) {
    if (inorder[i] == preorder[root]) {
      post(st, i, root + 1);
      post(i + 1, en, root + 1 + i - st);
      cout << preorder[root] << ' ';
      break;
    }
  }
}

void solve() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> preorder[i];
    for (int i = 0; i < n; i++) cin >> inorder[i];

    post(0, n, 0);
    cout << endl;
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