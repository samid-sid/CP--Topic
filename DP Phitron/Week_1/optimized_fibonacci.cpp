#include<bits/stdc++.h>
using namespace std;
unordered_map<int,long long > mp;
#define ll long long
ll arr[100];

ll fibo (int n)
{
    if(n <= 2) return 1;
    if(arr[n]!= 0){
        return arr[n];
    }
    arr[n] = fibo(n-1) + fibo(n-2);
    
    return arr[n];
}

int main()
{

   cout << fibo(5) << endl;
   cout << fibo(10) << endl;
   cout << fibo(50) << endl;
   cout << fibo(100) << endl;

    return 0;
}