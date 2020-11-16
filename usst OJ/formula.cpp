#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;

int main()
{
    long long n,a[300005];
    scanf("%lld",&n);
    _for(i,0,n)
        scanf("%lld",a+i);
    long long b[300005];
    long long ans=0,temp;
    _for(i,0,n-1)
        b[i]=abs(a[i]-a[i+1]);
    bool flag;
    flag=true;
    temp=0;
    _for(i,0,n-1)
    {
        if(flag)
        {
            temp+=b[i];
            flag=false;
        }
        else
        {
            temp-=b[i];
            flag=true;
        }
        if(temp<0)
        {
            temp=0;
            flag=true;
        }
        ans=max(temp,ans);
    }
    flag=true;
    temp=0;
    _for(i,1,n-1)
    {
        if(flag)
        {
            temp+=b[i];
            flag=false;
        }
        else
        {
            temp-=b[i];
            flag=true;
        }
        if(temp<0)
        {
            temp=0;
            flag=true;
        }
        ans=max(temp,ans);
    }
    cout<<ans;
    return 0;
}
