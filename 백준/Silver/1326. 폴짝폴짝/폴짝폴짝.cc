#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int bridge[10001];
int vst[10001];

void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> bridge[i];
  int st, en;
  cin >> st >> en;

  fill(vst, vst + n + 1, -1);
  queue<int> Q;
  Q.push(st);
  vst[st] = 0;
  while (!Q.empty()) {
    int cur = Q.front(); Q.pop();
    if (cur == en) break;
    int dbridge[2] = { bridge[cur], -bridge[cur] };
    for (int d = 0; d < 2; d++) {
      int k = 0;
      while (true) {
        k++;
        int nxt = cur + dbridge[d] * k;
        if (nxt < 1 || nxt >= n + 1) break;
        if (vst[nxt] > -1) continue;
        Q.push(nxt);
        vst[nxt] = vst[cur] + 1;
      }
    }
  }
  cout << vst[en];
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