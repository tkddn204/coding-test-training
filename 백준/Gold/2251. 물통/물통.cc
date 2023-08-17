#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

bool vst[201][201][201];
bool res[201];

void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  int cap[3] = {a, b, c};

  queue<tuple<int,int,int>> Q;
  Q.push({0, 0, c});
  vst[0][0][c] = true;
  while (!Q.empty()) {
    auto [wa, wb, wc] = Q.front(); Q.pop();
    
    if (wa == 0) res[wc] = true;
    
    int w[3] = {wa, wb, wc};
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (i == j) continue;
        if (w[i] == 0 or w[j] == cap[j]) continue;

        int tmp[3] = {w[0], w[1], w[2]};
        tmp[j] = min(cap[j], w[i] + w[j]);
        tmp[i] -= tmp[j] - w[j];
        
        if (vst[tmp[0]][tmp[1]][tmp[2]]) continue;
        vst[tmp[0]][tmp[1]][tmp[2]] = true;
        Q.push({tmp[0], tmp[1], tmp[2]});
      }
    }
  }
  for (int i = 0; i <= c; i++) {
    if (res[i]) cout << i << ' ';
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