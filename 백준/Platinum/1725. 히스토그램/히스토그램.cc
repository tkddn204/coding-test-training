#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

ll histogram[100005];

ll rec(int st, int en) {
  if (st >= en) return 0;
  if (st + 1 == en) return histogram[st];

  int mid = (st + en) / 2;
  ll res = max(rec(st, mid), rec(mid, en));

  ll w = 1;
  ll h = histogram[mid];

  int left = mid;
  int right = mid;
  while (right - left + 1 < en - st) {
    int a = -1;
    if (left > st) a = min(h, histogram[left - 1]);
    int b = -1;
    if (right < en) b = min(h, histogram[right + 1]);
    
    if (a >= b) h = a, left--;
    else h = b, right++;

    w++;
    res = max(res, w * h);
  }
  return res;
}

void solve() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> histogram[i];
  }

  cout << rec(0, n);
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