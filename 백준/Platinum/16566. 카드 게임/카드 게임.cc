#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int card[4000001];
bool chk[4000001];

void solve() {
  int n, m, k;
  cin >> n >> m >> k;

  for (int i = 0; i < m; i++) {
    cin >> card[i];    
  }
  sort(card, card + m);

  while (k--) {
    int num;
    cin >> num;

    int st = 0;
    int en = m - 1;
    while (st < en) {
      int mid = (st + en) / 2;
      if (card[mid] < num) {
        st = mid + 1;
      } else {
        en = mid;
      }
    }
    while (chk[en] || num >= card[en]) en++;
    chk[en] = true;
    cout << card[en] << endl;
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