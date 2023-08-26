#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int beer = 20;
    vector<tuple<int,int,bool>> point;
    int sx, sy, ex, ey;
    cin >> sx >> sy;
    for (int i = 0; i < n; i++) {
      int a, b;
      cin >> a >> b;
      point.push_back({a, b, false});
    }
    cin >> ex >> ey;
    
    queue<pair<int,int>> Q;
    Q.push({sx, sy});
    bool isEnd = false;
    while (!Q.empty()) {
      auto [x, y] = Q.front(); Q.pop();
      
      if (abs(ex - x) + abs(ey - y) <= 1000) {
        isEnd = true;
        break;
      }

      for (auto& [nx, ny, vst]: point) {
        if (vst) continue;
        int dis = abs(nx - x) + abs(ny - y);
        if (dis > 1000) continue;
        Q.push({nx, ny});
        vst = true;
      }
    }
    if (isEnd) cout << "happy" << endl;
    else cout << "sad" << endl;
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