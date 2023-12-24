#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n;
int s[101];

void man(int k) {
  int t = 1;
  while (k * t <= n) {
    s[k * t] = !s[k * t];
    t++;
  }
}

void woman(int k) {
  int t = 1;
  while (k - t >= 1 && k + t <= n) {
    if (s[k - t] != s[k + t]) break;
    t++;
  }
  int c = t - 1;
  for (int i = k - c; i <= k + c; i++) {
    s[i] = !s[i];
  }
}

void print() {
  for (int i = 1; i <= n; i++) {
    if (i != 1 && ((i - 1) % 20) == 0) cout << endl;
    cout << s[i] << ' ';
  }
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> s[i];
  int k;
  cin >> k;
  while (k--) {
    int a, b;
    cin >> a >> b;
    if (a == 1) man(b);
    else woman(b);
  }
  print();
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