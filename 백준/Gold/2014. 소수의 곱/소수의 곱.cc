#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

int k, n;
ll prime[101];
map<ll, bool> vst;
priority_queue<ll, vector<ll>, greater<>> pq;

void solve() {
  cin >> k >> n;
  for (int i = 0; i < k; i++) {
    cin >> prime[i];
    pq.push(prime[i]);
    vst[prime[i]] = true;
  }

  ll top = 0;
  for (int i = 0; i < n; i++) {
    top = pq.top(); pq.pop();
    for (int j = 0; j < k; j++) {
      ll nxt = top * prime[j];
      pq.push(nxt);
      if (top % prime[j] == 0) break;
    }
  }
  cout << top;
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