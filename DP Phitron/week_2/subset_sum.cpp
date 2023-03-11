#include<bits/stdc++.h>
using namespace std;
const int N = 105;
const int M = 1e5+5;

int dp[N][M];
int subset_sum(int arr[], int n , int tg)
{
    if(tg == 0) return 1;
    if(n < 0) return 0;

    if(dp[n][tg] != 0) return dp[n][tg];

    if(arr[n] <= tg)
    {
        return dp[n][tg] = (subset_sum(arr,n-1,tg-arr[n]) || subset_sum(arr,n-1,tg));
    }
    else{
        return dp[n][tg] = subset_sum(arr,n-1,tg);
    }
}
int Iterative(int arr[],int n , int sum)
{
   
    // if sum = 0
    for(int i=0;i<n;i++)
    {
        dp[i][0] = 1;
    }
    // if n = 0
    for(int i=1;i<=sum;i++)
    {
        dp[0][i] = 0;
    }

    for(int i=1;i<=n;i++)
    {
        for(int tg = 1;tg <=sum ;tg++){

            if(arr[i-1] <= tg)
            {
                dp[i][tg] = dp[i-1][tg-arr[i-1]] || dp[i-1][tg];
            }
            else{
                dp[i][tg] =  dp[i-1][tg];
            }
        }
    }

    return dp[n][sum];
}
void Take_input()
{
    int n = 6 , target = 9;
   int arr[] = {3, 34, 4, 12, 5, 2};
    // int tg = 30;
    // int arr[] = {3, 34, 4, 12, 5, 2};

//    int ans = subset_sum(arr,n-1,target);
   int ans = Iterative(arr,n,target);

   cout << ans << endl;

}
int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);

    int t = 1;
    // cin >> t;
    for(int i=1;i<=t;i++)
    {
        Take_input();
    }
    return 0;
}