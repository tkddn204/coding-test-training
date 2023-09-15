#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define MAX 'z' + 1

vector<int> graph[MAX];
int capacity[MAX][MAX];
int flow[MAX][MAX];
int pre[MAX];

void solve() {
  int n;
  cin >> n;

  while (n--) {
    char a, b;
    int c;
    cin >> a >> b >> c;
    graph[a].push_back(b);
    graph[b].push_back(a);
    capacity[a][b] += c;
    capacity[b][a] += c;
  }

  int res = 0;
  while (true) {
    queue<int> Q;
    fill(pre, pre + MAX, -1);
    Q.push('A');
    while (!Q.empty()) {
      int cur = Q.front(); Q.pop();
      
      for (auto nxt : graph[cur]) {
        if (flow[cur][nxt] < capacity[cur][nxt] and pre[nxt] == -1) {
          pre[nxt] = cur;
          Q.push(nxt);
          if (nxt == 'Z') break;
        }
      }
      if (pre['Z'] != -1) break;
    }
    
    if (pre['Z'] == -1) break;

    int f = 1e9;
    for (int i = 'Z'; i != 'A'; i=pre[i]) {
      f = min(f, capacity[pre[i]][i] - flow[pre[i]][i]);
    }
    for (int i = 'Z'; i != 'A'; i=pre[i]) {
      flow[pre[i]][i] += f;
      flow[i][pre[i]] -= f;
    }
    res += f;
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