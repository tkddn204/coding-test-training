#include<bits/stdc++.h>

using namespace std;

int A[200000][30], B[30];
int cnt[30], vst[30];

void solve() {
	int len = 0;
	string str;

	while (cin >> str && str != "-") {
		for (int j = 0; j < str.length(); j++)
			A[len][str[j] - 'A'] += 1;
    len++;
	}

	while (cin >> str && str != "#") {
    fill(B, B + 30, 0);
    fill(cnt, cnt + 30, -1);

		for (auto c : str) {
			B[c - 'A'] += 1;
			cnt[c - 'A'] = 0;
		}
		for (int i = 0; i < len; i++) {
      fill(vst, vst + 30, 0);
			bool possible = true;
			for (int k = 0; k < 26; k++) {
				if (B[k] - A[i][k] < 0) {
					possible = false;
					break;
				}
			}
			if (possible) {
				for (int k = 0; k < str.length(); k++) {
					if (A[i][str[k] - 'A'] > 0 && !vst[str[k] - 'A']) {
						cnt[str[k] - 'A'] += 1;
						vst[str[k] - 'A'] = 1;
					}
				}
			}
		}
		int minval = (int)1e9;
		int maxval = -1;
		for (int i = 0; i < 26; i++) {
			if (minval >= cnt[i] && cnt[i] != -1) minval = cnt[i];
			if (maxval <= cnt[i] && cnt[i] != -1) maxval = cnt[i];
		}
		string minans, maxans;
		for (int i = 0; i < 26; i++) {
			if (minval == cnt[i]) minans += i + 'A';
			if (maxval == cnt[i]) maxans += i + 'A';
		}
		cout << minans << " " << minval << " " << maxans << " " << maxval << "\n";
		
	}
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  // ios_base::sync_with_stdio(false);
  // cin.tie(0);
#endif
  solve();
  return 0;
}