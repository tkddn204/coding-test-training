#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
  while (true) {
    string s;
    cin >> s;
    if (s == "end") break;

    char mo[5] = {'a', 'e', 'i', 'o', 'u'};

    auto inmo = [&](char c) -> bool {
      for (char m : mo) {
        if (m == c) return true;
      }
      return false;
    };

    int mocnt[21] = {};
    int zacnt[21] = {};

    
    bool existmo = false;
    bool accept = true;
    
    int size = s.size();
    if (inmo(s[0])) {
      existmo = true;
      mocnt[0] = 1;
    } else zacnt[0] = 1;
    for (int i = 1; i < size; i++) {
      if (s[i - 1] == s[i]) {
        bool isee = s[i - 1] == 'e' && s[i] == 'e';
        bool isoo = s[i - 1] == 'o' && s[i] == 'o';
        if (!(isee || isoo)) {
          accept = false;
          break;
        }
      }
      if (inmo(s[i])) {
        existmo = true;
        mocnt[i] = mocnt[i - 1] + 1;
        if (mocnt[i] >= 3) {
          accept = false;
          break;
        }
      } else {
        zacnt[i] = zacnt[i - 1] + 1;
        if (zacnt[i] >= 3) {
          accept = false;
          break;
        }
      }
    }
    if (!existmo) accept = false;

    cout << '<' << s << "> is";
    cout << (accept ? " " : " not ");
    cout << "acceptable." << endl;
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