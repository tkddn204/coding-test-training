#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
  int n;
  cin >> n;

  map<string, int> mp;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    mp[s] = i;
  }

  int out[1001];
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    out[i] = mp[s];
  }

  int cnt = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (out[i] > out[j]) {
        cnt++;
        break;
      }
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