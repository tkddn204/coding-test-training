#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

vector<int> graph[500001];
bool vst[500001];
ll sum;

void dfs(int root, int cnt) {
  bool leaf = true;
  for (int nxt : graph[root]) {
    if (vst[nxt]) continue;
    leaf = false;
    vst[nxt] = true;
    dfs(nxt, cnt + 1);
  }
  if (leaf) sum += cnt;
}

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  vst[1] = true;
  dfs(1, 0);
  cout << (sum % 2 ? "Yes" : "No");
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