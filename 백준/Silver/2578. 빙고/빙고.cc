#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int pan[6][6];
bool chk[6][6];
pair<int,int> num[26];

bool bingo(int n) {
  auto [x, y] = num[n];
  chk[x][y] = true;

  int cnt = 0, t;
  for (int i = 0; i < 5; i++) {
    t = 0;
    for (int j = 0; j < 5; j++) {
      t += chk[i][j];
    }
    cnt += t == 5;
  }
  
  for (int i = 0; i < 5; i++) {
    t = 0;
    for (int j = 0; j < 5; j++) {
      t += chk[j][i];
    }
    cnt += t == 5;
  }
  
  t = 0;
  for (int i = 0; i < 5; i++) {
    t += chk[i][i];
  }
  cnt += t == 5;
  
  t = 0;
  for (int i = 0; i < 5; i++) {
    t += chk[i][4 - i];
  }
  cnt += t == 5;
  
  return cnt >= 3;
}

void solve() {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> pan[i][j];
      num[pan[i][j]] = {i, j};
    }
  }

  for (int i = 1; i <= 25; i++) {
    int k;
    cin >> k;
    if (bingo(k)) {
      cout << i;
      break;
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