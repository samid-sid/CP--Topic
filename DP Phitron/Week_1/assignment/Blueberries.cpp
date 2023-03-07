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
    for(int i=0;i<=k;i++)
    {
        for(int j=0;j<=n;j++)
        {
            dp[i][j] = -1;
        }
    }
    
    return fun(arr,n-1,k);
}


int main()
{
    int t = 1;
    cin >> t;
    for(int i=1;i<=t;i++)
    {
    //    cout <<  solve();
        int ans = solve();
        printf("Scenario #%d: %d\n",i,ans);
    }
    return 0;
}