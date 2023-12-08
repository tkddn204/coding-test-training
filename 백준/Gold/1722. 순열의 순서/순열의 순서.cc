#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

int n, k;
ll inp[21];
ll factorial[21];

void solve() {
  cin >> n;

  factorial[0] = 1;
  for (int i = 1; i <= n; i++) {
    factorial[i] = factorial[i - 1] * i;
  }

  int t;
  cin >> t;
  if (t == 1) {
    ll k;
    cin >> k;

    bool vst[n + 1] = {};
    ll res[n + 1] = {};

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (vst[j]) continue;
        if (k > factorial[n - i]) {
          k -= factorial[n - i];
        } else {
          vst[j] = true;
          res[i] = j;
          break;
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      cout << res[i] << ' ';
    }
  } else {
    for (int i = 1; i <= n; i++) cin >> inp[i];
    
    ll res = 1;
    bool vst[n + 1] = {};
    for (int i = 1; i <= n; i++) {
      for (int k = 1; k < inp[i]; k++) {
        if (vst[k]) continue;
        res += factorial[n - i];
      }
      vst[inp[i]] = true;
    }
    cout << res;
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