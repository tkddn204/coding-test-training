#include <string>
#include <vector>
#include <set>

using namespace std;

int parent[201];

int getParent(int x) {
    if (x == parent[x]) return x;
    return parent[x] = getParent(parent[x]);
}

void uniParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    
    if (a != b) parent[b] = a;
}

int solution(int n, vector<vector<int>> computers) {
    for (int i = 0; i < n; i++) parent[i] = i;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (!computers[i][j]) continue;
            if (getParent(i) == getParent(j)) continue;
            uniParent(i, j);
        }
    }
    
    for (int i = 0; i < n; i++) {
        parent[i] = getParent(parent[i]);
    }
    
    set<int> s;
    for (int i = 0; i < n; i++) {
        s.insert(parent[i]);
    }
    return s.size();
}