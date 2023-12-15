#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n, m, k;
vector<int> point;
map<int, bool> chk;

bool go(int mid) {
  int pre = point[0];
  int cnt = 1;
  for (int i = 1; i < k; i++) {
    if (point[i] - pre >= mid) {
      pre = point[i];
      cnt++;
    }
  }
  return cnt >= m;
}

void solve() {
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++) {
    int t;
    cin >> t;
    point.push_back(t);
    chk[t] = false;
  }

  int st = 0;
  int en = n;
  int mx = 0;
  while (st <= en) {
    int mid = (st + en) / 2;
    if (go(mid)) {
      st = mid + 1;
      mx = mid;
    } else {
      en = mid - 1;
    }
  }
  
  int pre = point[0];
  int cnt = 1;
  cout << 1;
  for (int i = 1; i < k; i++) {
    if ((point[i] - pre >= mx) && (cnt < m)) {
      cout << 1;
      pre = point[i];
      cnt++;
    } else {
      cout << 0;
    }
  }
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