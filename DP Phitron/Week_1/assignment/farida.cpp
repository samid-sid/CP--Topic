// link -> https://vjudge.net/problem/SPOJ-FARIDA

#include<bits/stdc++.h>
using namespace std;
// #define ll long long int
typedef long long  ll ;
const int N = 1e4+5;

ll fun(int arr[] , int n,ll dp[])
{
    if(n<1) return 0;
    if(n==1) return arr[1];
    
    if(dp[n] != 0) return dp[n];

    ll inc = arr[n] + fun(arr,n-2,dp);
    ll exc = fun(arr,n-1,dp);

    dp[n] = max(inc,exc);
    return dp[n];
}
void solve()
{
    int n;
    cin >> n;
    int arr[n+1];
    for(int i=1;i<=n;i++)
    {
        cin >> arr[i] ;
    }
    ll dp[n+1]={};
//    return  fun(arr,n,dp);
    // cout << ans << endl;

// Iterative  -----------
    dp[1] = arr[1];
    for(int i=2;i<=n;i++)
    {
        ll inc = arr[i] + dp[i-2];
        ll exc = dp[i-1];
        dp[i] = max(inc,exc);
    }
    // cout << dp[n] << endl;
}
int main()
{
    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++)
    {
        solve();
        // ll ans = solve();
        // printf("Case %d: %lld\n",i,ans);
    }
    return 0;
}