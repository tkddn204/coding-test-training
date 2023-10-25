#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
  string s;
  cin >> s;

  if (s.size() < 2 && s[0] < '9') {
    cout << (char)(s[0] + 1);
    return;
  }

  int len = s.size();
  int k = 0;
  bool isNine = true;
  for (auto c : s) {
    if (c != '9') {
      isNine = false;
      break;
    }
  }
  if (isNine) {
    cout << 1;
    for (int i = 1; i < len; i++) cout << 0;
    cout << 1;
    return;
  }

  int half = (len / 2) - (len % 2 == 0);
  string res = s;
  for (int i = 0; i <= half; i++) {
    res[len - 1 - i] = res[i];
  }

  int cur = half;
  while (res <= s) {
    if (res[cur] < '9') {
      res[cur] = res[len - 1 - cur] = res[cur] + 1;
    } else {
      while (res[cur] == '9') {
        res[cur] = res[len - 1 - cur] = '0';
        cur--;
      }
    }
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