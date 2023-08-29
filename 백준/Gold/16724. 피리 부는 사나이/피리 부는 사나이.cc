#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n, m;
int parent[1000001];
int nxt[1000001];

int getParent(int x) {
  if (x == parent[x]) return x;
  return parent[x] = getParent(parent[x]);
}

void uniParent(int a, int b) {
  a = getParent(a);
  b = getParent(b);
  if (a < b) parent[b] = a;
  else parent[a] = b;
}

void dfs(int cur) {
  int x = cur / m;
  int y = cur % m;

  if (getParent(cur) == getParent(nxt[cur])) return;
  uniParent(cur, nxt[cur]);
  dfs(nxt[cur]);
}

void solve() {
  cin >> n >> m;

  for (int i = 0; i <= n * m; i++) parent[i] = i;
  
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      int cur = i * m + j;
      int nxtIdx = cur;
      if (s[j] == 'U') nxtIdx -= m;
      else if (s[j] == 'D') nxtIdx += m;
      else if (s[j] == 'L') nxtIdx -= 1;
      else if (s[j] == 'R') nxtIdx += 1;
      nxt[cur] = nxtIdx;
    }
  }

  for (int i = 0; i < n * m; i++) {
    dfs(i);
  }
  
  set<int> s;
  for (int i = 0; i < n * m; i++) {
    s.insert(parent[i]);
  }
  cout << s.size();
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