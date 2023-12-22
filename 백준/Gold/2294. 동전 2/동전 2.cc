#include <bits/stdc++.h>

#define fore(i, a, b) for (int i = a; i < (int)b; i++)

using namespace std;

int n, k;
int arr[101];
int dp[10001];

int main()
{
    cin >> n >> k;
    fore(i, 1, n + 1) cin >> arr[i];
    fore(i, 1, k + 2) dp[i] = 100001;

    fore(i, 1, n + 1)
    {
        fore(j, arr[i], k + 1) dp[j] = min(dp[j], dp[j - arr[i]] + 1);
    }
    if (dp[k] == 100001)
        cout << -1 << '\n';
    else
        cout << dp[k] << '\n';
    return 0;
}
