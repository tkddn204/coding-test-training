#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int crane[51];
vector<int> box;
bool chk[10001];

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> crane[i];
  }
  sort(crane, crane + n, greater<>());
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int k;
    cin >> k;
    box.push_back(k);
  }
  sort(box.begin(), box.end(), greater<>());

  if (crane[0] < box[0]) {
    cout << -1;
    return;
  }

  int t = 0;
  while (!box.empty()) {
    vector<int> temp;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < box.size(); j++) {
        if (crane[i] < box[j]) continue;
        box.erase(box.begin() + j);
        break;
      }
    }
    t++;
  }

  cout << t;
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