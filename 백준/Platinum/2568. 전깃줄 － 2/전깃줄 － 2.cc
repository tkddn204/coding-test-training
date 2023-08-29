#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

vector<pair<int,int>> pole;

void solve() {
  int n;
  cin >> n;
  int len = 0;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    pole.push_back({a, b});
    len = max(len, a);
  }

  sort(pole.begin(), pole.end());

  vector<int> seq, idx;
  seq.push_back(pole[0].second);
  idx.push_back(0);  

  for (int i = 1; i < n; i++) {
    int b = pole[i].second;
    if (seq.back() < b) {
      seq.push_back(b);
      idx.push_back(seq.size() - 1);
    } else {
      int st = 0;
      int en = seq.size() - 1;
      while (st < en) {
        int mid = (st + en) / 2;
        if (b > seq[mid]) st = mid + 1;
        else en = mid;
      }
      seq[en] = b;
      idx.push_back(en);
    }
  }

  cout << n - seq.size() << endl;
  
  stack<int> res;
  int cur = seq.size() - 1;
  for(int i = idx.size() - 1; i >= 0; i--) {
    if (cur == idx[i]) cur--;
    else res.push(pole[i].first);
  }
  while (!res.empty()) {
    cout << res.top() << endl;
    res.pop();
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