#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

vector<int> primes;
void sieve(int n) {
  vector<bool> state(n+1, true);
  state[1] = false;
  for(int i = 2; i*i <= n; i++) {
    if (!state[i]) continue;
    for (int j = i*i; j <= n; j += i)
      state[j] = false;
  }
  for(int i = 2; i <= n; i++) {
    if (state[i]) primes.push_back(i);
  }
}

void solve() {
  int n, m;
  cin >> n >> m;
  sieve(m);

  for (int prime : primes) {
    if (prime >= n && prime <= m) cout << prime << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  solve();
  return 0;
}