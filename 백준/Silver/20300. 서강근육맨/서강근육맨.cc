#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

ll del[10001];

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> del[i];
  }
  sort(del, del + n);

  ll res = del[n - 1] * (n % 2);
  int st = 0;
  int en = n % 2 ? n - 2 : n - 1;
  while (st < en) {
    res = max(res, del[st] + del[en]);
    st++;
    en--;
  }
  cout << res;
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