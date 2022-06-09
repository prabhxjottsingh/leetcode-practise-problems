#include <bits/stdc++.h>
using namespace std;

int dp[1002][1002];

int func(int idxOne, int idxTwo, string s, string t)
{

    if (idxOne < 0 || idxTwo < 0)
        return 0;

    if (s[idxOne] == t[idxTwo])
    {
        return dp[idxOne][idxTwo] = (1 + func(idxOne - 1, idxTwo - 1, s, t));
    }

    if (dp[idxOne][idxTwo] != -1)
        return dp[idxOne][idxTwo];

    int caseOne = func(idxOne - 1, idxTwo, s, t);
    int caseTwo = func(idxOne, idxTwo - 1, s, t);
    return dp[idxOne][idxTwo] = max(caseOne, caseTwo);
}

int main()
{
    memset(dp, -1, sizeof(dp));
    string s, t;
    cin >> s >> t;
    int n = s.size();
    cout << func(n - 1, n - 1, s, t);
    cout << endl;
    string res(dp[n - 1][n - 1], 'a');
    int index = dp[n - 1][n - 1] - 1;
    int i = n - 1, j = n - 1;
    while ((i > -1) && (j > -1))
    {
        if (s[i] == t[j])
        {
            res[index] = s[i];
            i--;
            j--;
            index--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    cout << res;
}