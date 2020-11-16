#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

ull jie(int x)
{
    ull ans=1;
    while(x)
    {
        ans*=x;
        --x;
    }
    return ans;
}

ull c(int n,int m)
{
    return jie(n)/jie(n-m)/jie(m);
}

int main()
{
    int n;
    cin>>n;
    ///cout<<c(2*n,n)/(n+1);
    ull f[20];
    f[1]=1;
    for(int i=2;i<=n;++i)
        f[i]=f[i-1]*(4*i-2)/(i+1);
    cout<<f[n];
    return 0;
}
