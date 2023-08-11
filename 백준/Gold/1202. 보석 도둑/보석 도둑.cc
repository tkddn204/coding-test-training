#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define W first
#define V second

int n, k;
pair<int,int> bo[1000001];
int bag[1000001];
priority_queue<int> pq;

void solve() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int m, v;
    cin >> m >> v;
    bo[i] = {m, v};
  }
  sort(bo, bo + n);

  for (int i = 0; i < k; i++) {
    cin >> bag[i];
  }
  sort(bag, bag + k);

  int maxBoIdx = 0;
  ll sum = 0;
  for (int i = 0; i < k; i++) {
    while (maxBoIdx < n && bag[i] >= bo[maxBoIdx].W) {
      pq.push(bo[maxBoIdx++].V);
    }
    if (!pq.empty()) {
      sum += pq.top(); pq.pop();
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