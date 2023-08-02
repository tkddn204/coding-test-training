#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

vector<int> pre;

void rec(int left, int right) {
  if (left >= right) return;
  if (left == right - 1) {
    cout << pre[left] << endl;
    return;
  }

  int mid = left + 1;
  for (; mid < right; mid++) {
    if (pre[left] < pre[mid]) break;
  }

  rec(left + 1, mid);
  rec(mid, right);
  cout << pre[left] << endl;
}

void solve() {
  int k;
  while (cin >> k) pre.push_back(k);

  rec(0, pre.size());
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