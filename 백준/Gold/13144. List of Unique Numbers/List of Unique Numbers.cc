#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

int n;
int arr[100001];
bool chk[100001];

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  ll allsum = ((ll)n * (n + 1)) / 2;
  ll sum = 0;
  int st = 0;
  int en = 1;

  chk[arr[st]] = true;
  while (en < n) {
    if (chk[arr[en]]) {
      chk[arr[st++]] = false;
      sum += n - en;
    } else {
      chk[arr[en++]] = true;
    }
  }
  cout << allsum - sum;
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