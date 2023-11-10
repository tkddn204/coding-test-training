#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

int node[123457];
vector<int> graph[123457];

ll dfs(int parent, int cur) {
  ll sum = node[cur];
  for (int nxt: graph[cur]) {
    if (nxt == parent) continue;
    sum += dfs(cur, nxt);
  }
  return sum < 0 ? 0 : sum;
}

void solve() {
  int n;
  cin >> n;
  for (int i = 2; i <= n; i++) {
    char t; int a, p;
    cin >> t >> a >> p;
    if (t == 'W') a = -a;
    node[i] = a;
    graph[i].push_back(p);
    graph[p].push_back(i);
  }

  cout << dfs(1, 1);
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