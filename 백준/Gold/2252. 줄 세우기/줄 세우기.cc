#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n, m;
vector<int> arr[32001];
int deg[32001];

void solve() {
  int a, b;
  cin >> n >> m;
  while(m--) {
    cin >> a >> b;
    arr[a].push_back(b);
    deg[b]++;
  }
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (deg[i] == 0) q.push(i);
  }
  while (!q.empty()) {
    int cur = q.front(); q.pop();
    cout << cur << ' ';
    for (int nxt : arr[cur]) {
      deg[nxt]--;
      if (deg[nxt] == 0) q.push(nxt);
    }
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