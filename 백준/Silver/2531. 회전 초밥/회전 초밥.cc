#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int belt[30001];
int chk[3001];

void solve() {
  int n, d, k, c;
  cin >> n >> d >> k >> c;
  for (int i = 0; i < n; i++) {
    cin >> belt[i];
  }

  int res = 0;
  for (int i = 0; i < n; i++)
	{
		bool used = false;
		int eat = 0;
		for (int j = i; j < i + k; j++) {
			if (chk[belt[j % n]]) eat++;
			else chk[belt[j % n]] = 1;

			if (belt[j % n] == c) used = true;
		}
    res = max(res, k - eat + !used);
		fill(chk, chk + d + 1, 0);
	}

	cout << res;
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