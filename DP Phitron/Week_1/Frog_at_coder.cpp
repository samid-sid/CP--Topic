// https://atcoder.jp/contests/dp/tasks/dp_a

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int dp[N];
int arr[N];
int solve(int n)
{
    if(n == 1) return 0;

    if(dp[n] != 0) return dp[n];

    int a = solve(n-1) + abs(arr[n] - arr[n-1]);
    //corner case 
    // if(n == 2)
    // {
    //     dp[n] = a;
    //     return a;
    // }
    int b = solve(n-2) + abs(arr[n] - arr[n-2]);

    dp[n] = min(a,b);
    return dp[n];
    
}
int main()
{
    int n;
    cin >> n;

    for(int i=1; i<=n;i++)
    {
       cin >> arr[i];
    }

    if(n == 2)
    {
        int ans = abs(arr[2] - arr[1]);
        cout << ans << endl;
        return 0;
    }
    //recursive
    int ans = solve(n);
    cout << ans << endl;

    // Iterative
    // dp[1]  = 0;
    // for(int i=2;i<=n;i++)
    // {
    //     int a = dp[i-1] + abs(arr[i] - arr[i-1]);
    //     int b = dp[i-2] + abs(arr[i] - arr[i-2]);

    //     dp[i] = min(a,b);
    // }
    // cout << dp[n] << endl;
    return 0;
}