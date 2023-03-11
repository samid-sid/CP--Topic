#include<bits/stdc++.h>
using namespace std;
const int N = 100;
const int M = 100;
int dp[N][M];

int solve(int *arr, int n, int sum)
{
    if(sum == 0) return 1;
    if(n ==  0 ) return 0;

    if(dp[n][sum] != 0 ) return dp[n][sum];

    if(arr[n] <= sum)
    {
       return  dp[n][sum] = solve(arr,n-1,sum - arr[n]) + solve(arr,n-1,sum);
    }
    else{
        return dp[n][sum] = solve(arr,n-1,sum);
    }
}

void iterative(int *arr, int n , int sum)
{
    for(int i=0;i<=n;i++){
        dp[i][0] = 1;
    }
    for(int i=1;i<=sum;i++){
        dp[0][i] = 0;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout<<dp[n][sum]<<endl;
}
int main()
{
    int  n , sum;
    cin >> n >> sum;
    int arr[n];

    for(int i=0;i<n;i++)
    {
        cin >> arr[i] ;
    }
    iterative(arr,n,sum);
    // int ans = solve(arr,n,sum);
    // cout << ans << endl;

}

/*

3 5
2 3 5
o/p -> 2

6 10
2 3 5 6 8 10
o/p -> 3

4 6
1 2 3 3 
o/p -> 3
*/