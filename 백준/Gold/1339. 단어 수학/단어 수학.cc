#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

set<char> s;
string num[11];
map<char, int> m;

bool cmp(pair<char,int>& a, pair<char,int>& b) {
  if (a.second == b.second) {
    return a.first < b.first;
  }
  return a.second > b.second;
}

void solve() {
  int n;
  cin >> n;

  vector<pair<char, int>> v;
  for (int i = 0; i < n; i++) {
    cin >> num[i];
    int dgt = 1;
    for (int j = num[i].size() - 1; j >= 0; j--) {
      m[num[i][j]] += dgt;
      dgt *= 10;
    }
  }
  for (auto& it: m) v.push_back(it);
  sort(v.begin(), v.end(), cmp);

  int sum = 0;
  int val = 9;
  for (auto [a, b] : v) {
    sum += m[a] * val--;
  }

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