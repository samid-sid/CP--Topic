#include<bits/stdc++.h>
using namespace std;
const int N = 100;
int dp[N];

int solve (int n)
{
    if(n <= 3) return n;

    if(dp[n] != 0)
    {
        return dp[n];
    }
    dp[n] = solve(n-1) + solve(n-2);
    return dp[n];
}
int main()
{
    int n ;
    cin >> n;
    //-----recursive

    // cout << solve(n) << endl;

    //------Iterative
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    for(int i=4;i<=n;i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout << dp[n] << endl;


    return 0;
}