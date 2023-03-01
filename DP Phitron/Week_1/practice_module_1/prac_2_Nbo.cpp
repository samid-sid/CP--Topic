#include<bits/stdc++.h>
using namespace std;
const int N = 100;
int dp[N];
int n,k;
int solve(int k)
{
    if(k<=n) return 1;
    if(dp[k] != 0) return dp[k];

    int ans = 0;
    for(int i=1;i<=n;i++)
    {
        ans += solve(k-i);
    }
    dp[k] = ans;
    return ans;
}
int main()
{
    cin >> n >> k;

    // int ans = solve(k);
    // cout << ans <<endl;

    // Iterative ------

    for(int i=1;i<=n;i++)
    {
        dp[i] = 1;
    }

    for(int i=5;i<=k;i++)
    {
        int x = 0;
       for(int j=1;j<=n;j++)
       {
        x += dp[i-j] ;
       }
       dp[i] = x;
    }

    cout << dp[k] << endl;


    return 0;
}