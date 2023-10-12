#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

vector<pair<int, int>> arr;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int s, t;
    cin >> s >> t;
    if (s > t) swap(s, t);
    arr.push_back({s, t});
  }
  int d;
  cin >> d;

  auto cmp = [&](pair<int,int> a, pair<int,int> b) -> bool {
    auto [ast, aen] = a;
    auto [bst, ben] = b;
    
    if (aen == ben) return ast < bst;
    return aen < ben;
  };

  sort(arr.begin(), arr.end(), cmp);
  
  int mx = 0;
  int st = 0, en = d;
  for (auto [l, r] : arr) {
    if (r - l > d) continue;
    pq.push({l, r});
    
    // 범위 조정
    if (!(st <= l && r <= en)) {
      en = r;
      st = en - d;
    }

    // 뺄거 빼기
    while (!pq.empty() && !(st <= pq.top().first && pq.top().second <= en)) {
      pq.pop();
    }

    mx = max(mx, (int)pq.size());
  }
  cout << mx;
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