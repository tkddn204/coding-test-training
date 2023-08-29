#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int parent[100001];

int getParent(int x) {
  if (x == parent[x]) return x;
  return parent[x] = getParent(parent[x]);
}

void uniParent(int a, int b) {
  a = getParent(a);
  b = getParent(b) - 1;

  if (a != b) parent[a] = b;
}

void solve() {
  int n, p;
  cin >> n >> p;
  for (int i = 1; i <= n; i++) parent[i] = i;

  int cnt = 0;
  for (int i = 1; i <= p; i++) {
    int p;
    cin >> p;

    if (!getParent(p)) break;
    else {
      cnt++;
      uniParent(p, p);
    }
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