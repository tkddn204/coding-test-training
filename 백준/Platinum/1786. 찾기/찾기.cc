#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

vector<int> res;
vector<int> pi;

void getPi(string p) {
  int m = p.size(), j = 0;
  pi = vector<int>(m, 0);
  for (int i = 1; i < m; i++) {
    while (j > 0 and p[i] != p[j]) j = pi[j - 1];
    if (p[i] != p[j]) continue;
    pi[i] = ++j;
  }
}

void kmp(string t, string p) {
  getPi(p);
  int n = t.size(), m = p.size(), j = 0;
  for (int i = 0; i < n; i++) {
    while(j > 0 and t[i] != p[j]) j = pi[j - 1];
    if (t[i] != p[j]) continue;
    if (j == m - 1) {
      res.push_back(i - m + 1);
      j = pi[j];
    } else j++;
  }
}

void solve() {
  string t, p;
  getline(cin, t);
  getline(cin, p);
  kmp(t, p);
  cout << res.size() << endl;
  for (auto i : res) cout << i + 1 << ' ';
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