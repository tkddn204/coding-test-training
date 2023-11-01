#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

vector<string> info;

struct Trie {
  map<string, Trie*> mp;
  
  void insert(int idx) {
    if (idx >= info.size()) return;
    if (!mp[info[idx]]) mp[info[idx]] = new Trie;
    mp[info[idx]]->insert(idx + 1);
  }

  void find(int k) {
    for (auto [nxt, ntrie] : mp) {
      for (int i = 0; i < k; i++) cout << "--";
      cout << nxt << endl;
      ntrie->find(k + 1);
    }
  }
};

void solve() {
  int n;
  cin >> n;
  
  Trie* root = new Trie;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;

    info.clear();
    while (k--) {
      string t;
      cin >> t;
      info.push_back(t);
    }
    root->insert(0);
  }

  root->find(0);
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