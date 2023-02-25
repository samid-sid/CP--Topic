#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int INF = 2e9;
int dp[N];
int h[N];
int n, k;
int solve(int n)
{
    if (n == 1)
        return 0;

    if (dp[n] != 0)
        return dp[n];

    int ans = INF;
    for (int i = 1; i <= k; i++)
    {
        if (n - i <= 0)
            break;
        int tmp = solve(n - i) + abs(h[n] - h[n - i]);
        ans = min(ans, tmp);
    }
    dp[n] = ans;
    return ans;
}

int main()
{
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }
    // cout << solve(n) <<endl;

    // # Iterative

    dp[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = INF;
        for (int j = 1; j <= k; j++)
        {
            int from = i - j;
            if( from <= 0) break;
            int tmp = dp[from] + abs(h[i] - h[from]);
            dp[i] = min (dp[i] , tmp) ;
            
        }
    }
    cout << dp[n] << endl;

    return 0;
}