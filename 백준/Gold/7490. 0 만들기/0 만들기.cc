#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n;
char dx[] = {' ', '+', '-'};
bool vst[10][3];

bool isZero(string s) {
  s.erase(remove(s.begin(), s.end(), ' '), s.end());

  int cur = 0;
  int i = 0;
  for (; i < s.size(); i++) {
    if (!('0' <= s[i] && s[i] <= '9')) break;
    cur = cur * 10 + (s[i] - '0');
  }

  for (; i < s.size(); i++) {
    if ('0' <= s[i] && s[i] <= '9') continue;
    char h = s[i];

    int nxt = 0;
    int j = i + 1;
    for (; j < s.size(); j++) {
      if (!('0' <= s[j] && s[j] <= '9')) break;
      nxt = nxt * 10 + (s[j] - '0');
    }
    i = j - 1;
    
    if (h == '+') cur += nxt;
    else cur -= nxt;
  }

  return cur == 0;
}

void bt(int k, string s) {
  if (k == n + 1) {
    if (isZero(s)) cout << s << endl;
    return;
  }

  for (int d = 0; d < 3; d++) {
    if (vst[k][d]) continue;
    vst[k][d] = true;
    bt(k + 1, s + dx[d] + (char)(k + '0'));
    vst[k][d] = false;
  }
}

void solve() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < 3; i++)
      fill(vst[i], vst[i] + 10, false);
    bt(2, "1");
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