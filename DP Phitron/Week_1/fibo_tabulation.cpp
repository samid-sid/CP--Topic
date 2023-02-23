#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp [100];

int main()
{
    ll n;
    cin >> n;

    dp[1] = 0;
    dp[2] = 1;

    for(int i=3; i<=n;i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout << dp[n] << endl;
    return 0;
}