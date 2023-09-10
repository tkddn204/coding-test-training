#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int num[1000001];
bool card[1000001];
int score[1000001];

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    num[i] = k;
    card[k] = true;
  }

  for (int i = 0; i < n; i++) {
    for (int j = num[i] * 2; j < 1000001; j += num[i]) {
      if (card[j]) {
        score[num[i]]++;
        score[j]--;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << score[num[i]] << ' ';
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