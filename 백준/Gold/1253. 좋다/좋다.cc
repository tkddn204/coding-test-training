#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int num[2001];

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> num[i];
  sort(num, num + n);

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int st = 0, en = n - 1;
    while (st < en) {
      int sum = num[st] + num[en];
      if (num[i] == sum) {
        if (st != i && en != i) {
          cnt++;
          break;
        }
        if (st == i) st++;
        else if (en == i) en--;
      } else if (num[i] > sum) st++;
      else en--;
    }
  }
  cout << cnt;
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