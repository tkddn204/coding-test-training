// http://joonas-yoon.blogspot.com/2016/05/5015-ls.html
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)n; i++)
using namespace std;

string pattern;
int n;
string str;

int dp[101][101];
int plen, slen;

int dnq(int p, int s)
{
    if (p >= plen)
        return s == slen;

    int &r = dp[p][s];
    if (r != -1)
        return r;
    if (pattern[p] == '*')
        return r = dnq(p + 1, s) == true || dnq(p, s + 1) == true;
    if (pattern[p] == str[s])
        return r = dnq(p + 1, s + 1);

    return r = false;
}

int main()
{
    cin >> pattern;
    cin >> n;

    plen = pattern.size();

    forn(i, n)
    {
        memset(dp, -1, sizeof(dp));
        cin >> str;
        slen = str.size();
        if (dnq(0, 0) == true)
            cout << str << '\n';
    }

    return 0;
}
