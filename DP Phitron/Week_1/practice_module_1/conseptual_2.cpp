#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
const int N = 100;
int dp[N][N];
int ans;
int solve( vector<pair<int,int>> &vec ,int n, int cap)
{
    if(n<0 || cap <=0) return 0;
    if(dp[cap][n] != 0) return dp[cap][n];

    if(vec[n].F <= cap)
    {
        int nile = vec[n].S + solve(vec,n-1,cap-vec[n].F);
        int na_nile = solve(vec,n-1,cap);
        return dp[cap][n] = max(nile,na_nile);
        // return dp[n];
    }
    else
    {
    //    return  solve(vec,n-1,cap);
        return dp[cap][n] = solve(vec,n-1,cap);
        // return dp[n];
       
    }
}
int main()
{
    vector<pair<int,int>> vec;
    vec.push_back({2,3});
    vec.push_back({3,10});
    vec.push_back({4,5});
    vec.push_back({5,7});

     ans = solve(vec,3,7);
    cout << ans << endl;
    return 0;
}
