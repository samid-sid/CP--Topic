// https://atcoder.jp/contests/dp/tasks/dp_c

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int h[N][4] ;
int dp[N][4];
int n;
int solve(int n , int curr)
{
    if(n == 1) return h[n][curr];

    if(dp[n][curr] != 0 ) return dp[n][curr];

    int max_profit= 0;
    for(int x = 1;x<=3;x++)
    {
        if(x != curr){
        int tmp = solve(n-1,x) + h[n][curr];
        max_profit = max(max_profit, tmp);
        }
    }
    dp[n][curr] = max_profit;
    return max_profit;
}
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=3;j++)
        {
            cin >> h[i][j];
        }
    }

    int a= solve(n,1);
    int b = solve(n,2);
    int c = solve(n,3);

    int ans = max({a,b,c});
    cout << ans << endl;


    // Iterative -----> 

    // for(int i=1;i<=3;i++)
    // {
    //     dp[1][i] = h[1][i];
    // }

    // for(int day = 1;day<=n;day++)
    // {
    //     for(int curr = 1;curr <=3;curr++)
    //     {
    //         int max_profit = 0;

    //         for(int sel= 1;sel <= 3; sel++)
    //         {
    //             if(sel != curr) {

    //             int tmp = dp[day-1][sel] + h[day][curr];
    //             max_profit = max(max_profit,tmp);
    //             }
    //         }
    //         dp[day][curr] = max_profit;
    //     }
    // }

    // int ans = max({dp[n][1],dp[n][2],dp[n][3]});
    // cout << ans << endl;


    return 0;
}