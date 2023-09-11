#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n, k;
deque<int> d, r;

bool check() {
  int cnt = 0;
  for (int i = 0; i < n * 2; i++) {
    cnt += d[i] <= 0;
  }
  return cnt >= k;
}

void rotate() {
  d.push_front(d.back());
  d.pop_back();

  r.push_front(r.back());
  r.pop_back();  
  r[n - 1] = 0;
}

void move() {
  for (int i = n - 2; i >= 0; i--) {
    if (!r[i]) continue;
    if (!r[i + 1] and d[i + 1]) {
      swap(r[i], r[i + 1]);
      d[i + 1]--;
    }
  }
  r[n - 1] = 0;
}

void rift() {
  if (!r[0] and d[0]) {
    r[0] = 1;
    d[0]--;
  }
}

void solve() {
  cin >> n >> k;
  for (int i = 0; i < n * 2; i++) {
    int a;
    cin >> a;
    d.push_back(a);
    r.push_back(0);
  }

  int res = 1;
  while (true) {
    rotate();
    move();
    rift();

    if (check()) break;
    res++;    
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