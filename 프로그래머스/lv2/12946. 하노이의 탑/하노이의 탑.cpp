#include <string>
#include <vector>

using namespace std;

vector<vector<int>> answer;

void dfs(int from, int mid, int to, int n) {
    if (n == 0) return;
    dfs(from, to, mid, n - 1);
    vector<int> t = {from, to};
    answer.push_back(t);
    dfs(mid, from, to, n - 1);
}

vector<vector<int>> solution(int n) {
    
    dfs(1, 2, 3, n);
    
    return answer;
}