#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n;
int three[13];

void go(int n) {
  if (n == 0) {
    cout << '-';
    return;
  }

  go(n - 1);
  for (int i = 0; i < three[n - 1]; i++) cout << ' ';
  go(n - 1);
}

void solve() {
  three[0] = 1;
  for (int i = 1; i <= 12; i++)
    three[i] = three[i - 1] * 3;
  while (cin >> n) {
    go(n);
    cout << endl;
  }
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