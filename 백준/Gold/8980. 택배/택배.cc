#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define tp tuple<int,int,int>
int n, c, m;
vector<tp> box;

bool cmp(tp& a, tp& b) {
  auto [as, ad, ac] = a;
  auto [bs, bd, bc] = b;

  if (as == bs) {
    if (ad == bd) return ac < bc;
    return ad < bd;
  }
  return as < bs;
}

void solve() {
  cin >> n >> c >> m;
  for (int i = 0; i < m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    box.push_back({x, y, z});
  }
  sort(box.begin(), box.end(), cmp);

  int res = 0;
  int town[n + 1] = {};
  for (auto [s, d, w]: box) {
    int maxtruck = *max_element(town + s, town + d);
    int truck = min(w, c - maxtruck);
    res += truck;
    for (int t = s; t < d; t++) {
      town[t] += truck;
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