#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    vector<pair<int,int>> vp;
    int a, b;
    for (int i = 0; i < n ; i++) {
      cin >> a >> b;
      vp.push_back({a, b});
    }

    sort(vp.begin(), vp.end());
    
    int cur = 0, res = 1;
		for(int i = 1; i < n; i++) {
			if(vp[cur].second > vp[i].second){
				cur = i;
				res++;
			}
		}
    cout << res << endl;
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