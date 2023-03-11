// link - > https://vjudge.net/problem/AtCoder-dp_d

#include<bits/stdc++.h>
using namespace std;
// typedef  long long   ll ;
#define ll long long
typedef pair<int,int> PII;
const int N = 1e5+5;
ll dp[105][N];
// int n,k;
ll knapsack(PII arr[], int n,int w)
{
  if(n < 0 || w == 0 ) return 0;

  if(dp[n][w] != 0) return dp[n][w];

  if(arr[n].first <= w)
  {
       ll inc = arr[n].second + knapsack(arr,n-1,w-arr[n].first);
       ll exc = knapsack(arr,n-1,w);
       
      return  dp[n][w] = max(inc,exc);
  }
  else {
    return dp[n][w] =  knapsack(arr,n-1,w);
  }

}
ll tabulation(PII arr[],int n, int w)
{
     
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {      
           if(arr[i].first <= j)
            {
                dp[i][j] = max(dp[i-1][j-arr[i].first] + arr[i].second , dp[i-1][j]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][w];
}
void Take_input()
{
   int n,w;
   cin >> n >> w;
   PII arr[n+1];
   for(int i=1;i<=n;i++)
   {
    cin >> arr[i].first >> arr[i].second ;
   }

//    ll ans = knapsack(arr,n-1,w);
   ll ans = tabulation(arr,n,w);
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
/*

4 60
20 70
30 80
40 90
70 200

*/