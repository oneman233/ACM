#include <bits/stdc++.h>
using namespace std;

long long n,m,k,x;

long long qpow(long long k)
{
    long long ans=1;
    long long temp=10;
    while(k)
    {
        if(k%2==1)
        {
            ans*=temp;
            ans%=n;
        }
        temp*=temp;
        temp%=n;
        k/=2;
    }
    return ans;
}

int main()
{
    cin>>n>>m>>k>>x;
    cout<<((m*(qpow(k)%n))%n+x)%n;
    return 0;
}

/*
simplify pow(k)%n
*/
