#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n,m;
bool vst1[16]; // 세로
bool vst2[32]; // 왼쪽대각
bool vst3[32]; // 오른쪽대각
int cnt = 0;

void rec(int c) {
  if (c == n) {
    cnt++;
    return;
  }

  for (int i = 0 ; i < n; i++) {
    if (vst1[i] || vst2[i + c] || vst3[c - i + n - 1]) {
      continue;
    }
    vst1[i] = true;
    vst2[i + c] = true;
    vst3[c - i + n - 1] = true;
    rec(c + 1);
    vst1[i] = false;
    vst2[i + c] = false;
    vst3[c - i + n - 1] = false;
  }
}

void solve() {
  cin >> n;
  rec(0);
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