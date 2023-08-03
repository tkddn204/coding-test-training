#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  bool chk[n] = {};
  stack<int> st;
  for (int i = 0; i < n; i++) {
    while (!st.empty() and s[st.top()] < s[i] and k > 0) {
      chk[st.top()] = true;
      st.pop();
      k--;
    }
    st.push(i);
  }
  if (k > 0) {
    for (int i = n - 1; i >= 0; i--) {
      if(!chk[i]) {
        chk[i] = true;
        k--;
      }
      if (k <= 0) break;
    }
  }
  for (int i = 0; i < n; i++) {
    if (!chk[i]) cout << s[i];
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