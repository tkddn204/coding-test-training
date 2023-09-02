#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int card[4000001];
int parent[4000001];

int getParent(int x) {
  if (x == parent[x]) return parent[x];
  return parent[x] = getParent(parent[x]);
}

void uniParent(int x, int y) {
  x = getParent(x);
  y = getParent(y);
  
  if (x < y) parent[x] = y;
  if (x > y) parent[y] = x;
}

void solve() {
  int n, m, k;
  cin >> n >> m >> k;

  for (int i = 0; i < m; i++) {
    cin >> card[i];
    parent[i] = i;
  }
  sort(card, card + m);

  while (k--) {
    int num;
    cin >> num;
    
    int st = 0;
    int en = m - 1;
    while (st < en) {
      int mid = (st + en) / 2;
      if (card[mid] <= num) {
        st = mid + 1;
      } else {
        en = mid;
      }
    }

    en = getParent(en);
    cout << card[en] << endl;
    uniParent(en, en + 1);
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