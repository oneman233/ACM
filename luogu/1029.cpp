#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a,long long b)
{
    if(b>a)
    {
        long long tmp=a;
        a=b;
        b=tmp;
    }
    while(b)
    {
        long long tmp=a%b;
        a=b;
        b=tmp;
    }
    return a;
}

int main()
{
    long long x,y,ans=0;
    cin>>x>>y;
    for(int i=x;i<=y;i+=x)
    {
        int j=x*y/i;
        if(i*j/gcd(i,j)==y)
            ans++;
    }
    cout<<ans;
    return 0;
}
