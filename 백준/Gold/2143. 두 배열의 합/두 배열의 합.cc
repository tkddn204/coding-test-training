#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

int t, n, m;
int a[1001], b[1001];
ll suma[1001], sumb[1001];
vector<int> parta, partb;
ll cnt;

void solve() {
  cin >> t;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    suma[i] = suma[i - 1] + a[i];
    for (int j = 0; j < i; j++) {
      parta.push_back(suma[i] - suma[j]);
    }
  }
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    sumb[i] = sumb[i - 1] + b[i];
    for (int j = 0; j < i; j++) {
      partb.push_back(sumb[i] - sumb[j]);
    }
  }
  sort(partb.begin(), partb.end());

  for (auto pa: parta) {
    int diff = t - pa;
    auto ub = upper_bound(partb.begin(), partb.end(), diff);
    auto lb = lower_bound(partb.begin(), partb.end(), diff);
    cnt += ub - lb;
  }

  cout << cnt;  
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