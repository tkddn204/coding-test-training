#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n, e;
vector<pair<int, int>> graph[801];
int dis[801];
int v1, v2;

int dk(int a, int b) {
  fill(dis, dis + n + 1, (int)1e9);
  
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
  dis[a] = 0;
  pq.push({0, a});
  while (!pq.empty()) {
    auto [d, x] = pq.top(); pq.pop();

    for (auto [nd, nx]: graph[x]) {
      nd += d;
      if (nd < dis[nx]) {
        dis[nx] = nd;
        pq.push({nd, nx});
      }
    }
  }
  // cout << a << "->" << b << " : ";
  // for (int i = 1; i <= n; i++) {
  //   if (dis[i] >= (int)1e9) cout << '-' << ' ';
  //   else cout << dis[i] << ' ';
  // }
  // cout << " = " << dis[b] << endl;
  return dis[b];
}

int go(int path[4]) {
  int sum = 0;
  for (int i = 0; i < 3; i++) {
    int a = path[i];
    int b = path[i + 1];
    if (a == b) continue;
    int len = dk(a, b);
    if (len >= (int)1e9) {
      sum = -1;
      break;
    } else sum += len;
  }
  return sum;
}

void solve() {
  cin >> n >> e;
  while (e--) {
    int a, b, c;
    cin >> a >> b >> c;
    graph[a].push_back({c, b});
    graph[b].push_back({c, a});
  }
  cin >> v1 >> v2;
  
  int path[] = {1, v1, v2, n};
  int sum1 = go(path);
  int path2[] = {1, v2, v1, n};
  int sum2 = go(path2);
  if (sum1 == -1 or sum2 == -1) {
    cout << -1;
  } else {
    cout << (min(sum1, sum2));
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