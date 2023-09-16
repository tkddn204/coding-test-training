#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

/*
  1. 문제이해
  - 최소 벽부수기
  - (101, 101)
  2. 아이디어
    1. BFS vst
      - 백트래킹 불가능
      - BFS로 가능한가?
      - vst[k(벽)][n][m] = 벽 부순 개수 or 방문체크
        - k는 최대 101*101개
        - 10000*10000 10억개이므로 불가능
    2. dp
      - 1일때만 + 1 해주는식
      - dp에 1e9 채우기
      - dp 점화식
        - if(n-1 있음?) dp[n][m] = min(dp[n][m], dp[n-1][m] + 지금벽);
        - if(m-1 있음?) dp[n][m] = min(dp[n][m], dp[n][m-1] + 지금벽);
      - n^2로 체크할텐데, 우회해서 벽을 안부수는 경우도 있을테니 불가능
    3. BFS vst
      - 다른 방법의 vst를 생각
      - vst[n][m] = 벽 부순 개수?
      - 이렇게하면 큰 vst찾아 떠날텐데..
      - 일단시도
    
  3. 슈도코드
    
*/

// 풀이

int mp[101][101];
int vst[101][101];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void solve() {
  int m, n;
  cin >> m >> n;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      mp[i][j] = s[j] - '0';
    }
  }
  for (int i = 0; i < n; i++)
    fill(vst[i], vst[i] + m, 1e9);

  queue<pair<int,int>> Q;
  Q.push({0, 0});
  vst[0][0] = mp[0][0];
  while (!Q.empty()) {
    auto [x, y] = Q.front(); Q.pop();

    for (int d = 0; d < 4; d++) {
      int nx = x + dx[d];
      int ny = y + dy[d];

      if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
      int nval = vst[x][y] + mp[nx][ny];
      if (nval < vst[nx][ny]) {
        vst[nx][ny] = nval;
        Q.push({nx, ny});
      }
    }
  }
  
  cout << vst[n - 1][m - 1];
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