#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

int dice[6];

void solve() {
  ll n;
  cin >> n;
  for (int i = 0; i < 6; i++) cin >> dice[i];

  ll sum = 0;

  if (n == 1) {
    sort(dice, dice + 6);
    for (int i = 0; i < 5; i++) sum += dice[i];
    cout << sum;
    return;
  }

  ll one = *min_element(dice, dice + 6);
  ll two = LLONG_MAX;
  for (int i = 0; i < 6; i++) {
    for (int j = i + 1; j < 6; j++) {
      if (i + j == 5) continue;
      two = min(two, (ll)(dice[i] + dice[j]));
    }
  }

  ll three = LLONG_MAX;
  for (int i = 0; i < 6; i++) {
    for (int j = i + 1; j < 6; j++) {
      if (i + j == 5) continue;
      for (int k = j + 1; k < 6; k++) {
        if (j + k == 5 || i + k == 5) continue;
        three = min(three, (ll)(dice[i] + dice[j] + dice[k]));
      }
    }
  }

  sum += one * (n - 2) * (n - 2) * 5;
  sum += one * (n - 2) * 4;

  sum += two * (n - 2) * 4;
  sum += two * (n - 1) * 4;

  sum += three * 4;

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