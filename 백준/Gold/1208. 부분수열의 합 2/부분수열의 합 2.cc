#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

int n, s;
int lim;
int arr[41];
ll cnt;
map<int, int> sm;

void rec(int cur, int sum) {
  if (cur >= lim) {
    if(lim == n) cnt += sm[s - sum];
    else sm[sum]++;
    return;
  }

  rec(cur + 1, sum + arr[cur]);
  rec(cur + 1, sum);
}

void solve() {
  cin >> n >> s;
  for(int i = 0; i < n; i++) cin >> arr[i];

  lim = n / 2; rec(0, 0);
  lim = n; rec(n / 2, 0);
  
  cout << (cnt - (s == 0));
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