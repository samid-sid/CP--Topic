// link - > https://vjudge.net/problem/SPOJ-RPLB

#include<bits/stdc++.h>
using namespace std;
// #define ll long long int
typedef long long  ll ;
const int N = 1005;
int dp[N][N];
// int n,k;
int fun(int *arr, int n,int mx)
{
    if(n < 0 || mx <=0) return 0;


    if(dp[mx][n] != -1 ) return dp[mx][n];

    if(arr[n] <= mx)
    {
        int inc = arr[n] + fun(arr, n -2 , mx - arr[n]);
        int exc = fun(arr,n-1,mx);
        return dp[mx][n] = max(inc,exc);

    }
    else 
    {
        return dp[mx][n] = fun(arr,n-1,mx);
    }


}
int solve()
{
    int n , k;
    cin >> n >> k;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin >> arr[i] ;
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            dp[i][j] = 0;
        }
    }

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            if(i ==0 || j ==0) {
                dp[i][j] = 0;
                // continue;
            }

            if(arr[i] <= j)
            {
                dp[i][j]= max(dp[i-2][j-arr[i-2]] + arr[i], dp[i-1][j]);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[n][k] << endl;
    
    // return fun(arr,n-1,k);
}


int main()
{
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        solve();
        // int ans = solve();
        // printf("Scenario #%d: %d\n",i,ans);
    }
    return 0;
}