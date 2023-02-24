#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 100;
ll dp[N];

ll tribo (ll n)
{
    if(n <= 3) return 1;

    if(dp[n] != 0)
    {
        return dp[n];
    }

    ll ans = tribo(n-1) + tribo(n-2) + tribo(n-3);
    dp[n] = ans;
    return ans;
}
int main()
{
    ll n ;
    cin >> n;
    //-----recursive

    // cout << tribo(n) << endl;

    //------Iterative
    dp[1] = dp[2] = dp[3] = 1;

    for(int i=4;i<=n;i++)
    {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    cout << dp[n] << endl;

 
    return 0;
}