#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int stone[3];
bool vst[1501][1501];
int sum;

int isSame() {
  queue<pair<int, int>> Q;
  Q.push({stone[0], stone[1]});
  vst[stone[0]][stone[1]] = true;
  while (!Q.empty()) {
    auto [a, b] = Q.front(); Q.pop();

    int nxt[3] = {a, b, sum - a - b};
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (nxt[i] >= nxt[j]) continue;
        int tmp[3] = {a, b, sum - a - b};
        tmp[i] += nxt[i];
        tmp[j] -= nxt[i];
        if (tmp[j] < 0) continue;
        if (vst[tmp[0]][tmp[1]]) continue;
        Q.push({tmp[0], tmp[1]});
        vst[tmp[0]][tmp[1]] = true;
      }
    }
  }
  return vst[sum / 3][sum / 3];
}

void solve() {
  for (int i = 0; i < 3; i++) {
    cin >> stone[i];
    sum += stone[i];
  }
  if (sum % 3 != 0) cout << 0;
  else cout << isSame();
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