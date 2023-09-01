#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

struct line {
  pair<int,int> st, en;
};

vector<line> lines;
int parent[3001];

int getParent(int x) {
  if (x == parent[x]) return x;
  return parent[x] = getParent(parent[x]);
}

void uniParent(int a, int b) {
  a = getParent(a);
  b = getParent(b);
  
  if (a != b) parent[b] = a;
}

ll ccw(pair<int,int> a, pair<int,int> b, pair<int,int> c) {
  auto [ax, ay] = a;
  auto [bx, by] = b;
  auto [cx, cy] = c;

  ll s = (ax * by + bx * cy + cx * ay);
  s -= (bx * ay + cx * by + ax * cy);

  return s < 0 ? -1 : s > 0;
}

bool isCross(line a, line b) {
  auto [ast, aen] = a;
  auto [bst, ben] = b;

  ll k = ccw(ast, aen, bst) * ccw(ast, aen, ben);
  ll t = ccw(bst, ben, ast) * ccw(bst, ben, aen);

  if (k == 0 and t == 0) {
    if (ast > aen) swap(ast, aen);
    if (bst > ben) swap(bst, ben);
    return bst <= aen && ast <= ben;
  }
  
  return k <= 0 && t <= 0;
}

void solve() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    parent[i] = i;
  }

  for (int i = 0; i < n; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    lines.push_back({{a, b}, {c, d}});
  }

  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (isCross(lines[i], lines[j])) {
        uniParent(i, j);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    parent[i] = getParent(parent[i]);
  }

  set<int> group;
  for (int i = 0; i < n; i++) group.insert(parent[i]);
  cout << group.size() << endl;
  
  int cnt[3001] = {};
  for (int i = 0; i < n; i++) {
    cnt[parent[i]]++;
  }
  cout << *max_element(cnt, cnt + n);
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