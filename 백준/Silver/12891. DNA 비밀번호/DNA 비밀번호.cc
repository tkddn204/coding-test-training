#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int lim[255];
int num[255];
char alpha[] = {'A', 'C', 'G', 'T'};

bool chk() {
  for (auto a: alpha) {
    if (num[a] < lim[a]) return false;
  }
  return true;
}

void solve() {
  int n, p;
  cin >> n >> p;
  string s;
  cin >> s;
  cin >> lim['A'] >> lim['C'] >> lim['G'] >> lim['T'];

  for (int i = 0; i < p; i++) num[s[i]]++;
  int cnt = chk();
  for (int i = 0; i < n - p; i++) {
    num[s[i]]--; num[s[p + i]]++;
    cnt += chk();
  }

  cout << cnt;
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