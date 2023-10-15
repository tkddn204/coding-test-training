#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

bool cal[1001][367];

bool isFilled(int i, int s, int e) {
  for (int j = s; j <= e; j++) {
    if (cal[i][j]) return true;
  }
  return false;
}

void solve() {
  int n;
  cin >> n;
  vector<pair<int,int>> inp;
  while (n--) {
    int s, e;
    cin >> s >> e;
    inp.push_back({s, e});
  }

  auto cmp = [&](pair<int,int> a, pair<int,int> b) -> bool {
    auto [as, ae] = a;
    auto [bs, be] = b;
    if (as == bs) {
      return (ae - as) > (be - bs);
    }
    return as < bs;
  };
  sort(inp.begin(), inp.end(), cmp);

  int mh = 0, sw = 366, ew = 0;
  for (auto [s, e] : inp) {
    for (int i = 0; i < 1001; i++) {
      if (isFilled(i, s, e)) continue;
      for (int j = s; j <= e; j++) {
        cal[i][j] = true;
      }
      mh = max(mh, i + 1);
      sw = min(sw, s);
      ew = max(ew, e);
      break;
    }
  }

  int sum = 0;
  int w = 0, h = 0;
  for (int j = sw; j <= ew + 1; j++) {
    bool filled = false;
    for (int i = 0; i <= mh; i++) {
      if (!cal[i][j]) continue;
      filled = true;
      h = max(h, i + 1);
    }
    w++;
    if (!filled) {
      w--;
      sum += w * h;
      w = 0, h = 0;
    }
  }
  cout << sum;
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